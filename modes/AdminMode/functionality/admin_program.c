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
sint_32 Admin_sint32UploadDatabases(void){
	(void) Std_sint32UploadDatabase(); // upload student database 
	return User_sint32UploadDatabase(); // upload the login info of the student
}

sint_32 Admin_sint32CheckLogin(uint_8* ID, uint_8* Password){
	if(ID != NULL && Password != NULL){
		sint_32 Rec_Index = Admin_Insint32CheckRec(ID);
		if(Rec_Index >= 0){
			if(!strcmp(Password, AdminsInfo[Rec_Index].password)){
				printf("\nWelcome Back %s!", AdminsInfo[Rec_Index].full_name);
				return Rec_Index;
			}	
		}
		return -1;
	}
	else{
		return -2;
	}
}

sint_32 Admin_sint32EditPassword(uint_8* ID){
	if(ID != NULL){
		sint_32 Rec_Index = Admin_Insint32CheckRec(ID);
		printf("Enter Your New Password : ");
		(void) Admin_Insint32GetString(&AdminsInfo[Rec_Index].password);
		printf("Password updated!\n");
		return 1;	
	}
	else{
		return -2;
	}
}

sint_32 Admin_sint32ViewAllDatabase(void){
	printf("\t\t(full Name)\t\t\t\t(ID)\t\t(Gender)\t\t(Age)\t\t(Year Degree)\n");
	for(int i = 0; i < Std_sint32GetDatabaseLength(); i++){
		(void) Std_sint32ViewBrief(i); // printf a row with a brief about the student
	}
	return 1; // done
}

sint_32 Admin_sint32ViewStudent(uint_8* ID){
	// if id is not null (empty string) 
	if(ID != NULL){
		// get the index of the student record in the students database
		sint_32 Rec_Index = Std_sint32Search(ID);
		// view the record
		if(Rec_Index >= 0){
			(void) Std_sint32ViewRecord(Rec_Index);	
			return 1; // function worked, id is correct
		}
		else{
			printf("Entered ID is not correct\n");
		}
	}
	else{
		return -2; // null pointer
	}
}

sint_32 Admin_sint32RemoveAllDatabase(void){
	// remove the student database
	(void) Std_sint32RemoveAll();
	// remove the user login database
	return User_sint32RemoveAllUsers();
}

sint_32 Admin_sint32RemoveStudent(uint_8* ID){
	if(ID != NULL){
		(void) Std_sint32RemoveRec(ID);
		(void) User_sint32RemoveUser(ID);
		return 1;
	}
	else{
		return -2;
	}
}

sint_32 Admin_sint32EditGrades(uint_8* ID){
	if(ID != NULL){
		(void) Std_sint32EditGrades(ID);
		return 1;
	}
	else{
		return -2;
	}
}

sint_32 Admin_sint32AddStudent(uint_8* ID){
	if(ID != NULL){
		// add name, id, gender, age, grades
		(void) Std_sint32AddRec(ID);
		// add new password
		(void) User_sint32AddUser(ID);
		printf("Student added successfully!");
		return 1;
	}
	else{
		return -2;
	}
}

static inline sint_32 Admin_Insint32CheckRec(uint_8* ID){
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

static inline sint_32 Admin_Insint32GetString(uint_8** Str){
	// initialize the memory space with 35 unsigned characters
	*Str = (uint_8*) malloc(35 * sizeof(uint_8));
	scanf(" %[^\n]", *Str); // reading the string 
	// reallocating a space fits the string length
	*Str = (uint_8*) realloc(*Str, strlen(*Str) + 1);
	
	return 1; // worked as expected
}

static inline sint_32 Admin_Insint32CopyRec(Admin_t* NewRec, const Admin_t Rec){
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