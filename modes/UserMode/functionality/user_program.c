#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\..\..\Libraries\STD_TYPES.h"
#include "..\..\..\Student_Database\functionality\student_prototypes.h"
#include "..\Database\userDB.h"
#include "user_private.h"


// including user database into this file, to use or modify it
extern User_t UserLoginInfo[NUMBER_OF_USERS];

// following the database length
static sint_32 User_DatabaseLength = NUMBER_OF_USERS;

// this pointer enables us to modify on the database in the runtime, with memory allocation
static User_t *User_Database = NULL;

/*************************************************************************************************/

sint_32 User_sint32UploadDatabase(void){
	// Allocating memory fits the existing database
	User_Database = (User_t*) malloc(User_DatabaseLength * sizeof(User_t));
	if(User_Database != NULL){
		// copying the records
		for(int i = 0; i < User_DatabaseLength; i++){
			User_Insint32CopyRecord(&User_Database[i], UserLoginInfo[i]);
		}
		return 1; // function worked
	}
	else{
		// null pointer is assigned to the database
		return -2;
	}
}


sint_32 User_sint32CheckLogin(uint_8* ID, uint_8* Pswrd){
	if(ID != NULL && Pswrd != NULL){
		// searching for the record index
		sint_32 RecIndex = User_Insint32CheckRec(ID);
		uint_8* Username;
		// if it returned a valid index
		if(RecIndex >= 0){
			// it will return 0 if the entered password matches the one in the data base
			if(!strcmp(Pswrd, User_Database[RecIndex].Password)){
				Std_sint_32GetName(ID, &Username);
				printf("Welcome Back, %s\n\n", Username);
				return RecIndex; // enable access to the record
			}
		}
		return -1; // password is not correct
	}
	else{
		return -2; // one or both of the parameter is null pointer
	}
}


sint_32 User_sint32ViewStdRec(uint_8* ID){
	if(ID != NULL){
		// geting the index of the record contains this ID from student database
		sint_32 RecIndex = Std_sint32Search(ID);
		if(RecIndex >= 0){
			(void) Std_sint32ViewRecord(RecIndex);
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


sint_32 User_sint32EditUsername(uint_8* ID){
	if(ID != NULL){
		// searching for this id in the student database
		sint_32 RecIndex = Std_sint32Search(ID);
		if(RecIndex >= 0){
			return Std_sint32EditName(RecIndex);
		}
		else{
			printf("Enterd ID is not Correct!\n");
			return -1; // wrong id
		}
	}
	else{
		return -2; // null pointer 
	}
}

sint_32 User_sint32EditPassword(uint_8* ID){
	if(ID != NULL){
		// searching for the index of the user record
		sint_32 Record_Index = User_Insint32CheckRec(ID);
		//deleting the old password
		free(User_Database[Record_Index].Password);
		// Getting the new password
		printf("Enter New Password : ");
		User_Insint32GetString(&User_Database[Record_Index].Password);
		printf("Password Edited Successfully");
	}
	else{
		return -1;
	}
}

sint_32 User_sint32AddUser(uint_8* ID){
	// increase the user database by one;
	User_DatabaseLength++;
	// reallocating space larger than the old one by one
	User_Database = realloc(User_Database, User_DatabaseLength * sizeof(uint_8*));
	
	// copying the ID of the student into the user login database
	User_Database[User_DatabaseLength - 1].User_ID = (uint_8*) malloc(strlen(ID) + 1);
	strcpy(User_Database[User_DatabaseLength - 1].User_ID, ID);
	
	// making a password for the new record
	printf("Enter a Password : ");
	(void) User_Insint32GetString(&User_Database[User_DatabaseLength - 1].Password);
}

sint_32 User_sint32RemoveUser(uint_8* ID){
	if(User_Database != NULL){
		if(ID != NULL){
			// getting the index of the record to be deleted from the user database
			sint_32 RecIndex = User_Insint32CheckRec(ID);
			if(RecIndex >= 0){
				// allocating a new empty database with a smaller size, to copy the existing database into it 
				User_t* NewDB = (User_t*) malloc(User_DatabaseLength * sizeof(User_t));
				// copying the records into the new database, but we won't copy the record that we will remove
				for(int i = 0, j = 0; i < User_DatabaseLength; i++){
					// if i not the index of the record we will remove
					if(i != RecIndex){
						// copying records
						User_Insint32CopyRecord(&NewDB[j], User_Database[i]);
						j++;
					}
				}
				
				// Decreasing the Database by 1
				User_DatabaseLength--;
				
				// free the old database
				free(User_Database);
				
				// get the new database
				User_Database = NewDB;
				NewDB = NULL;
				// returning the new length of the database means that the function worked as we expected
				return User_DatabaseLength;
			}
			else{
				return -1; // wrong id
			}
		}
		else{
			// null pointer
			return -2;
		}	
	}
	else{
		return -3; // empty database
	}
}

sint_32 User_sint32RemoveAllUsers(void){
	if(User_Database != NULL){
		// check if database is not empty
		if(User_Database != NULL){
			// remove database
			free(User_Database);
			User_Database = NULL;
			User_DatabaseLength = 0;
			return 1; // worked
		}
		else{
			return -2; // null pointer
		}	
	}
	else{
		return -3; // empty Database
	}
}
 
static inline sint_32 User_Insint32CheckRec(uint_8* ID){
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


static inline sint_32 User_Insint32GetString(uint_8** Str){
	// initialize the memory space with 35 unsigned characters
	*Str = (uint_8*) malloc(35 * sizeof(uint_8));
	scanf(" %[^\n]", *Str); // reading the string 
	// reallocating a space fits the string length
	*Str = (uint_8*) realloc(*Str, strlen(*Str) + 1);
	
	return 1; // worked as expected
}

static inline sint_32 User_Insint32CopyRecord(User_t* NewRec, const User_t Rec){
	if(NewRec != NULL){
		// allocating memory fits the id length
		NewRec->User_ID = (uint_8*) malloc(strlen(Rec.User_ID) + 1);
		// copying the id
		strcpy(NewRec->User_ID, Rec.User_ID);
		
		// allocating memory fits the Password
		NewRec->Password = (uint_8*) malloc(strlen(Rec.Password) + 1);
		// copying the password
		strcpy(NewRec->Password, Rec.Password);
		
		return 1; // worked as expected
	}
	else{
		return -2;
	}

}