#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\..\Libraries\STD_TYPES.h"
#include "..\Database\students.h"
#include "private.h"

// this global variable follows the growth of the database
uint_32 DatabaseLength = STUDENT_NUM;

// using the database in this file
extern Student_t Database_of_Students[STUDENT_NUM];

//pointer to the array of records
Student_t* ptr_Database;

/************************************************************************************************/

uint_32 Std_uint32UploadDatabase(void){
	// allocatting a memory that fits the current database
	ptr_Database = (Student_t*) malloc(DatabaseLength * sizeof(Student_t));
	
	for(uint_16 i = 0; i < DatabaseLength; i++){
		// copy the old i(th) record into the new memory place
		Std_Inuint32CopyRec(ptr_Database[i], Database_of_Students[i]);
	}
}


uint_32 Std_uint32Search(uint_8* ID){
	for(uint_16 i = 0; i < DatabaseLength; i++){
		// strcmp is a function that compares two strings and returns 0 if they equal each other
		if(!strcmp(Database_of_Students[i].Std_ID, ID)){
			return i; // if the given id equals the id of the i(th) record, return the index of this record
		}
	}
	return -1; // if the given id is not existed in the database, return -1
}

uint_32 Std_uint32RemoveRec(uint_8* ID){
	// get the index of the record
	uint_32 Record_Index = Std_Inuint32Search(ID);
	// defining a new database that is less than the older by 1 student record
	Student_t* NewPtr_Database = (Student_t*) malloc((DatabaseLength - 1) * sizeof(Student_t));
	
	for(uint_16 i = 0; i < DatabaseLength; i++){
		// the strcmp returns 0 if the two strings are equal, here if they are not equal
		// it means this record is not the one to be deleted, so we store it in the new memory
		if(strcmp(ptr_Database[i].Stud_ID, ID)){
			// copy the old i(th) record into the new memory place, except the record 
			// that we want to delete
			Std_Inuint32CopyRec(NewPtr_Database[i], ptr_Database[i]);
		}
	}
	// decrease the follower of the database length by 1, as 1 record is actually now deleted
	DatabaseLength--;
	// free the old memory
	free(ptr_Database);
	// assign the pointer to the new memory
	ptr_Database = NewPtr_Database;
	// we don't need the new pointer then we assign it to NULL
	NewPtr_Database = NULL;
}

uint_32 Std_uint32AddRec(void){
	// increase the follower of database length by 1
	DatabaseLength++;
	// reallocate a memory with the new size
	ptr_Database = realloc(ptr_Database, DatabaseLength * sizeof(Student));
	
	// Reading the name of the new student
	printf("Enter The Student Full Name: ");
	Std_Inuint32GetString(&ptr_Database[DatabaseLength - 1].full_name);
	
	// Reading the ID of the new student
	printf("Enter the Student ID: ");
	Std_Inuint32GetString(&ptr_Database[DatabaseLength - 1].Std_ID);
	
	// Reading the Gender of the new student
	printf("Enter the Student gender: ");
	Std_Inuint32GetString(&ptr_Database[DatabaseLength - 1].gender);
	
	// Reading the Age of the new student
	printf("Enter the Student age: ");
	scanf("%i", &ptr_Database[DatabaseLength - 1].age);
	
	// Reading the Grades of the new student
	printf("Enter the Student greades: ");
	for(uint_16 j = 0; j < SUBJECTS_NUM; j++){
		scanf("%f", &ptr_Database[DatabaseLength - 1].grades[j]);
	}
}


uint_32 Std_uint32EditName(uint_32* ID){
	// get the index of the student record
	uint_32 Record_Index = Std_Inuint32Search(ID);
	// delete the old name
	free(ptr_Database[Record_Index].full_name);
	// assign the pointer to NULL
	ptr_Database[Record_Index].full_name = NULL;
	
	// get the new name
	printf("Enter the new Full Name: ");
	Std_Inuint32GetString(&ptr_Database[Record_Index].full_name);
	// view changes for the user
	printf("Student name changed to : %s", ptr_Database[Record_Index].full_name);
}

uint_32 Std_uint32EditGrades(uint_32* ID){
	// get the index of the student record
	uint_32 Record_Index = Std_Inuint32Search(ID);
	// get the new grades from the Admin
	printf("Enter the New Gerades : ");
	for(uint_16 i = 0; i < SUBJECTS_NUM; i++){
		scanf("%i", &ptr_Database[Record_Index].grades[j]);
	}
	// view the new changes for the admin 
	printf("%s's grades has changed to :\n", ptr_Database[Record_Index].full_name);
	for(uint_16 i = 0; i < SUBJECTS_NUM; i++){
		printf("%i\n", ptr_Database[Record_Index].grades[j]);
	}
}

uint_32 Std_uint32GetDatabaseLength(void){
	return DatabaseLength;
}


static inline uint_32 Std_Inuint32Search(uint_8* ID){
	for(uint_16 i = 0; i < DatabaseLength; i++){
		// strcmp is a function that compares two strings and returns 0 if they equal each other
		if(!strcmp(Database_of_Students[i].Std_ID, ID)){
			return i; // if the given id equals the id of the i(th) record, return the index of this record
		}
	}
	return -1; // if the given id is not existed in the database, return -1
}

static inline uint_32 Std_Inuint32GetString(uint_8** Str){
	// allocatting enough memory (at first only) as we don't know
	// how long the string will be.
	*Str = (uint_8*) malloc(35 * sizeof(uint_8));
	
	scanf("%s", *Str); // reading the string
	
	// reallocatting a memory that fits the string we has just read
	*Str = realloc(*Str, strlen(*Str) + 1);
}

static inline uint_32 Std_Inuint32CopyRec(Student* Ptr, const Student* O_Ptr){
	/**********storing the student name***********/
	// allocating memory that fits the length of the name
	Ptr[i].full_name = (uint_8*) malloc(strlen(O_Ptr[i].full_name) + 1);
	// copying the name in the database to the ptr_Database
	strcpy(Ptr[i].full_name, O_Ptr[i].full_name);

	/*********storing the ID*********************/
	// allocating memory that fits the length of the ID
	Ptr[i].Std_ID = (uint_8*) malloc(strlen(O_Ptr[i].Std_ID) + 1);
	// copying the ID in the database to the ptr_Database
	strcpy(Ptr[i].Std_ID, O_Ptr[i].Std_ID);

	/*********storing the Gender*********************/
	// allocating memory that fits the length of the Gender
	Ptr[i].gender = (uint_8*) malloc(strlen(O_Ptr[i].gender) + 1);
	// copying the Gender in the database to the ptr_Database
	strcpy(Ptr[i].gender, O_Ptr[i].gender);

	/*********storing the Age*********************/
	Ptr[i].age = O_Ptr[i].age;

	/*********storing the Grades*********************/
	for(uint_16 j = 0; j < SUBJECTS_NUM; j++){
		Ptr[i].grades[j] = O_Ptr[i].grades[j];
	}
}