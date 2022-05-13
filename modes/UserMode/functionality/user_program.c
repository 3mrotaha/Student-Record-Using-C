#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "STD_TYPES.h"
#include "user_private.h"
#include "..\Database\userDB.h"
#include "..\..\..\Student_Database\functionality\student_prototypes.h"
#include "..\..\..\Student_Database\Database\studentDB.h"

// including user database into this file, to use or modify it
extern User_t UserLoginInfo[NUMBER_OF_USERS];

// including student database into this file, to use or modify it
extern Student_t* ptr_Database;
 
// following the database length
uint_32 User_DatabaseLength = NUMBER_OF_USERS;

// this pointer enables us to modify on the database in the runtime, with memory allocation
User_t *User_Database;

/*************************************************************************************************/

uint_32 User_uint32UploadDatabase(void){
	// Allocating memory fits the existing database
	User_Database = (User_Database*) malloc(User_DatabaseLength * (User_t));
	if(User_Database != NULL){
		// copying the records
		for(int i = 0; i < User_DatabaseLength; i++){
			User_InUint32CopyRecord(&User_Database[i], &UserLoginInfo[i]);
		}
		return 1; // function worked
	}
	else{
		// null pointer is assigned to the database
		return -2;
	}
}


uint_32 User_uint32CheckLogin(uint_8* ID, uint_8* Pswrd){
	if(ID != NULL && Pswrd != NULL){
		// searching for the record index
		uint_32 RecIndex = User_InUint32CheckRec(ID);
		// if it returned a valid index
		if(RecIndex >= 0){
			// it will return 0 if the entered password matches the one in the data base
			if(!strcmp(Pswrd, User_Database[RecIndex].Password))
				return RecIndex; // enable access to the record
		}
		return -1; // password is not correct
	}
	else{
		return -2; // one or both of the parameter is null pointer
	}
}


uint_32 User_uint32ViewStdRec(uint_8* ID){
	if(ID != NULL){
		// geting the index of the record contains this ID from student database
		uint_32 RecIndex = Std_uint32Search(ID);
		if(RecIndex >= 0){
			(void) Std_uint32ViewRecord(RecIndex);
			// returning the index of the record, assures that the function worked as we expected
			return RecIndex;
		}
		else{
			// the ID is not in the database
			return -1;
		}
	}
	else{
		// null pointer is assigned to ID
		return -2;
	}
}


uint_32 User_uint32EditUsername(uint_8* ID){
	if(ID != NULL){
		// searching for this id in the student database
		RecIndex = Std_uint32Search(ID);
		if(RecIndex >= 0){
			(void) Std_uint32EditName(RecIndex);
			return 1;
		}
		return 1; // worked as expected
	}
	else{
		return -2; // null pointer 
	}
}


uint_32 User_uint32EditPassword(uint_32 Record_Index){
	if(ID != NULL){
		// searching for the index of this record in the user database
		if(Record_Index >= 0){
			//deleting the old password
			free(User_Database[Record_Index].Password);
			// Getting the new password
			printf("Enter New Password : ");
			User_InUint32GetString(&User_Database[Record_Index].Password);
			printf("Password Edited Successfully");
		}
	}
	else{
		return -2;
	}
}


uint_32 User_uint32AddUser(void){
	// the index of the new student will be the last one
	Rec_index = Std_uint32GetDatabaseLength() - 1;
	// increase the user database by one;
	User_DatabaseLength++;
	// reallocating space larger than the old one by one
	User_Database = realloc(User_Database, User_DatabaseLength * sizeof(uint_8*));
	// copying the ID of the student into the user login database
	strcpy(User_Database[User_DatabaseLength - 1].User_ID, ptr_Database[Rec_index]);
	
	// making a password for the new record
	printf("Enter a Password : ");
	(void) User_InUint32GetString(&User_Database[User_DatabaseLength - 1].Password);
}


uint_32 User_uint32RemoveUser(uint_8* ID){
	
}


static inline uint32 User_InUint32CheckRec(uint_8* ID){
	if(ID != NULL){
		// searching for the record index
		for(int i = 0; i < User_DatabaseLength; i++){
			// the string compare function returns 0 if the two strings equal each other
			if(!strcmp(User_Database[i].User_ID, ID)){
				return i; // the index of the wanted record
			}
		}
		// if the function returned this value it means the ID, is not in the database
		return -1;
	}
	else{
		// if the function returned this value it means it didn't work as we expected
		return -2;
	}
}


static inline uint32 User_InUint32GetString(uint_8** Str){
	if(*Str != NULL){
		// initialize the memory space with 35 unsigned characters
		*Str = (uint_8*) malloc(35 * sizeof(uint_8));
		scanf("%s", *Str); // reading the string 
		// reallocating a space fits the string length
		*Str = (uint_8*) realloc(*Str, strlen(*Str) + 1);
		
		return 1; // worked as expected
	}
	else{
		return -2;
	}
	
}

static inline uint32 User_InUint32CopyRecord(User_t* NewRec, User_t* Rec){
	if(NewRec != NULL && Rec != NULL){
		// allocating memory fits the id length
		NewRec->User_ID = (uint_8*) malloc(strlen(Rec->User_ID) + 1);
		// copying the id
		strcpy(NewRec->User_ID, Rec->User_ID);
		
		// allocating memory fits the Password
		NewRec->Password = (uint_8*) malloc(strlen(Rec->Password) + 1);
		// copying the password
		strcpy(NewRec->Password, Rec->Password);
		
		return 1; // worked as expected
	}
	else{
		return -2;
	}

}