#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\..\..\Libraries\STD_TYPES.h"
#include "..\..\..\Student_Database\functionality\student_prototypes.h"
#include "..\..\UserMode\functionality\user_prototypes.h"
#include "..\Database\AdminDB.h"
#include "admin_private.h"
#include "admin_prototypes.h"

// array of the records 
extern Admin_t AdminsInfo[NUMBER_OF_ADMINS];

/*******************************************************************************************/
uint_32 Admin_uint32UploadDatabases(void){
	(void) Std_uint32UploadDatabase(); // upload student database 
	return User_uint32UploadDatabase(); // upload the login info of the student
}

uint_32 Admin_uint32CheckLogin(uint_8* ID, uint_8* Password){
	if(ID != NULL && Password != NULL){
		uint_32 Rec_Index = Admin_InUint32CheckRec(ID);
		if(Rec_Index >= 0){
			if(!strcmp(Password, AdminsInfo[Rec_Index].password)){
				return Rec_Index;
			}	
		}
		return -1;
	}
	else{
		return -2;
	}
}

uint_32 Admin_uint32EditPassword(uint_8* ID){
	if(ID != NULL){
		uint_32 Rec_Index = Admin_InUint32CheckRec(ID);
		printf("Enter Your New Password : ");
		(void) Admin_InUint32GetString(&AdminsInfo[Rec_Index].password);
		printf("Password updated!");
		return 1;	
	}
	else{
		return -2;
	}
}

uint_32 Admin_uint32ViewAllDatabase(void){
	printf("\t\t\t(Name)\t\t\t(ID)\t\t\t(Gender)\t\t\t(Age)\t\t\t(Year Degree)");
	for(int i = 0; i < Std_uint32GetDatabaseLength(); i++){
		(void) Std_uint32ViewBrief(i); // printf a row with a brief about the student
	}
	return 1; // done
}

uint_32 Admin_uint32ViewStudent(uint_8* ID){
	// if id is not null (empty string) 
	if(ID != NULL){
		// get the index of the student record in the students database
		uint_32 Rec_Index = Std_uint32Search(ID);
		// view the record 
		(void) Std_uint32ViewRecord(Rec_Index);
		return 1; // function worked 
	}
	else{
		return -2; // null pointer
	}
}

uint_32 Admin_uint32RemoveAllDatabase(void){
	// remove the student database
	(void) Std_uint32RemoveAll();
	// remove the user login database
	return User_uint32RemoveAllUsers();
}

uint_32 Admin_uint32RemoveStudent(uint_8* ID){
	if(ID != NULL){
		(void) Std_uint32RemoveRec(ID);
		(void) User_uint32RemoveUser(ID);
		return 1;
	}
	else{
		return -2;
	}
}

uint_32 Admin_uint32EditGrades(uint_8* ID){
	if(ID != NULL){
		(void) Std_uint32EditGrades(ID);
		return 1;
	}
	else{
		return -2;
	}
}

uint_32 Admin_uint32AddStudent(uint_8* ID){
	if(ID != NULL){
		// add name, id, gender, age, grades
		(void) Std_uint32AddRec(ID);
		// add new password
		(void) User_uint32AddUser(ID);
		printf("Student added successfully!");
		return 1;
	}
	else{
		return -2;
	}
}

static inline uint_32 Admin_InUint32CheckRec(uint_8* ID){
	if(ID != NULL){
		for(int i = 0; i < NUMBER_OF_ADMINS; i++){
			if(!strcmp(ID, AdminsInfo[i].admin_ID)){
				return i;
			}
		}
		return -1;
	}
	else{
		return -2;
	}
}

static inline uint_32 Admin_InUint32GetString(uint_8** Str){
	if(Str != NULL){
		*Str = (uint_8*) malloc(35 * sizeof(uint_8));
		scanf("%s", *Str);
		*Str = realloc(*Str, strlen(*Str) + 1);
		return 1;
	}
	else{
		return -2;
	}
}

static inline uint_32 Admin_InUint32CopyRec(Admin_t* NewRec, const Admin_t Rec){
	if(NewRec != NULL){
		/*************Copying the name********************/
		NewRec->full_name = (uint_8*) malloc(strlen(Rec.full_name) + 1);
		strcpy(NewRec->full_name, Rec.full_name);
		
		/*************Copying the name********************/
		NewRec->admin_ID = (uint_8*) malloc(strlen(Rec.admin_ID) + 1);
		strcpy(NewRec->admin_ID, Rec.admin_ID);
		
		/*************Copying the name********************/
		NewRec->password = (uint_8*) malloc(strlen(Rec.password) + 1);
		strcpy(NewRec->password, Rec.password);
		
		return 1;	
	}
	else{
		return -2;
	}
}