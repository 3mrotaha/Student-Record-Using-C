#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\..\Libraries\STD_TYPES.h"
#include "..\Database\studentsDB.h"
#include "student_private.h"

// this global variable follows the growth of the database
uint_32 DatabaseLength = STUDENT_NUM;

// using the database in this file
extern Student_t Database_of_Students[STUDENT_NUM];

//pointer to the array of records
Student_t* ptr_Database = NULL;

/************************************************************************************************/

uint_32 Std_uint32UploadDatabase(void){
	// allocatting a memory that fits the current database
	ptr_Database = (Student_t*) malloc(DatabaseLength * sizeof(Student_t));
	
	if(ptr_Database != NULL){
		for(uint_16 i = 0; i < DatabaseLength; i++){
		// copy the old i(th) record into the new memory place
		Std_Inuint32CopyRec(&ptr_Database[i], &Database_of_Students[i]);
		}
		
		// this return value can be used to ensure that the function worked as we expected
		return 1;
	}
	else{
		// this returned value tells the developer that this function has crashed
		// or didn't work as we expected
		return -1;
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
	if(ID != NULL){
		// get the index of the record
		uint_32 Record_Index = Std_Inuint32Search(ID);
		// defining a new database that is less than the older by 1 student record
		Student_t* NewPtr_Database = (Student_t*) malloc((DatabaseLength - 1) * sizeof(Student_t));
		
		for(uint_16 i = 0; i < DatabaseLength; i++){
			// if i is not the index of the record we will remove
			if(i != Record_Index){
				// copy the old i(th) record into the new memory place, except the record 
				// that we want to delete
				Std_Inuint32CopyRec(&NewPtr_Database[i], &ptr_Database[i]);
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
		
		// this return value can be used to ensure that the function worked as we expected
		return DatabaseLength;
	}
	else{
		// this returned value tells the developer that this function has crashed
		// or didn't work as we expected
		return -2;
	}

}

uint_32 Std_uint32RemoveAll(void){
	// check if the database is not empty
	if(ptr_Database != NULL){
		// free the database
		free(ptr_Database);
		ptr_Database = NULL;
		return 1; // worked
	}
	else{
		return -2; // null pointer
	}
}

uint_32 Std_uint32AddRec(uint_8* ID){
	if(ID != NULL){
		// increase the follower of database length by 1
		DatabaseLength++;
		// reallocate a memory with the new size
		ptr_Database = realloc(ptr_Database, DatabaseLength * sizeof(Student_t));
				
		// Reading the ID of the new student
		ptr_Database[DatabaseLength - 1].Std_ID = (uint_8*)malloc(strlen(ID) + 1);
		strcpy(ptr_Database[DatabaseLength - 1].Std_ID, ID);
		
		// Reading the name of the new student
		printf("Enter The Student Full Name: ");
		Std_Inuint32GetString(&ptr_Database[DatabaseLength - 1].full_name);
		
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
		
		// returning the length of the database means the function worked as we excepted
		return DatabaseLength;
	}
	else{
		return -2; // pointer is null
	}
}

uint_32 Std_uint32EditName(uint_32 Record_Index){
	if(Record_Index >= 0){
		// delete the old name
		free(ptr_Database[Record_Index].full_name);
		// get the new name
		printf("Enter the new Full Name: ");
		Std_Inuint32GetString(&ptr_Database[Record_Index].full_name);
		// view changes for the user
		printf("Student name changed to : %s", ptr_Database[Record_Index].full_name);
		// this return value can be used to ensure that the function worked as we expected
		return 1;
	}
	else{
		// the record does not exist
		return -1;
	}

}

uint_32 Std_uint32EditGrades(uint_8* ID){
	if(ID != NULL){
		// get the index of the student record
		uint_32 Record_Index = Std_Inuint32Search(ID);
		// get the new grades from the Admin
		printf("Enter the New Gerades : ");
		for(uint_16 i = 0; i < SUBJECTS_NUM; i++){
			scanf("%i", &ptr_Database[Record_Index].grades[i]);
		}
		// view the new changes for the admin 
		printf("%s's grades has changed to :\n", ptr_Database[Record_Index].full_name);
		for(uint_16 i = 0; i < SUBJECTS_NUM; i++){
			printf("%i\n", ptr_Database[Record_Index].grades[i]);
		}
		// this return value can be used to ensure that the function worked as we expected
		return 1;
	}
	else{
		// this returned value tells the developer that this function has crashed
		// or didn't work as we expected
		return -1;
	}

}

uint_32 Std_uint32GetDatabaseLength(void){
	return DatabaseLength;
}

uint_32 Std_uint32ViewRecord(uint_32 Record_Index){
	if(Record_Index >= 0){
		printf("*****************************************\n");
		printf("*\t\t\t\t\t\t\t\t\t\t*\n");
		printf("* Name   : %s\t\t\t\t\t\t\t*\n", ptr_Database[Record_Index].full_name);
		printf("* ID     : %s\t\t\t\t\t\t\t*\n", ptr_Database[Record_Index].Std_ID);
		printf("* Gender : %s\t\t\t\t\t\t\t*\n", ptr_Database[Record_Index].gender);
		printf("* Age    : %i\t\t\t\t\t\t\t*\n", ptr_Database[Record_Index].age);
		printf("*****************************************\n");
		printf("* Grades : \t\t\t\t\t\t\t\t*\n");
		Std_InvidPrintGrades(ptr_Database[Record_Index].grades);
		printf("*\t\t\t\t\t\t\t\t\t\t*\n");
		printf("* Total Grades : %0.2f%%", Std_Inf32TotalGrades(ptr_Database[Record_Index].grades));
		Std_InvidGPA(Std_Inf32TotalGrades(ptr_Database[Record_Index].grades), SUBJECTS_NUM * 100);
		printf("\t\t\t*\n");
		printf("*\t\t\t\t\t\t\t\t\t\t*\n");
		printf("******************************************\n");
		return 1; // worked as we expected
	}
	else{
		// the index does not exist
		return -1;
	}
	
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
	if(*Str != NULL){
		// allocatting enough memory (at first only) as we don't know
		// how long the string will be.
		*Str = (uint_8*) malloc(35 * sizeof(uint_8));
		
		scanf("%s", *Str); // reading the string
		
		// reallocatting a memory that fits the string we has just read
		*Str = realloc(*Str, strlen(*Str) + 1);
		// this return value can be used to ensure that the function worked as we expected
		return 1;
	}
	else{
		// this returned value tells the developer that this function has crashed
		// or didn't work as we expected
		return -1;
	}
}

static inline uint_32 Std_Inuint32CopyRec(Student_t* Ptr, const Student_t* O_Ptr){
	if(Ptr != NULL && O_Ptr != NULL){
		/**********storing the student name***********/
		// allocating memory that fits the length of the name
		Ptr->full_name = (uint_8*) malloc(strlen(O_Ptr->full_name) + 1);
		// copying the name in the database to the ptr_Database
		strcpy(Ptr->full_name, O_Ptr->full_name);

		/*********storing the ID*********************/
		// allocating memory that fits the length of the ID
		Ptr->Std_ID = (uint_8*) malloc(strlen(O_Ptr->Std_ID) + 1);
		// copying the ID in the database to the ptr_Database
		strcpy(Ptr->Std_ID, O_Ptr->Std_ID);

		/*********storing the Gender*********************/
		// allocating memory that fits the length of the Gender
		Ptr->gender = (uint_8*) malloc(strlen(O_Ptr->gender) + 1);
		// copying the Gender in the database to the ptr_Database
		strcpy(Ptr->gender, O_Ptr->gender);

		/*********storing the Age*********************/
		Ptr->age = O_Ptr->age;

		/*********storing the Grades*********************/
		for(uint_16 j = 0; j < SUBJECTS_NUM; j++){
			Ptr->grades[j] = O_Ptr->grades[j];
		}
		// this return value can be used to ensure that the function worked as we expected
		return 1;
	}
	else{
		// this returned value tells the developer that this function has crashed
		// or didn't work as we expected
		return -1;
	}
}

static inline void Std_InvidPrintGrades(f32 grades[]){
	for(int i = 0; i < SUBJECTS_NUM; i++){
		switch(i){
			case 0:
				printf("*\t\t\tMath -> ");
			break;
			case 1:
				printf("*\t\t\tPhysics -> ");
			break;
			case 2:
				printf("*\t\t\tContol -> ");
			break;
			case 3:
				printf("*\t\t\tLogic -> ");
			break;
			case 4:
				printf("*\t\t\tElectronics -> ");
			break;
		}
		printf("%0.2f\t\t\t", grades[i]);
		Std_InvidGPA(grades[i], 100);
		printf("\t*\n");
	}
}

static inline f32 Std_Inf32TotalGrades(f32 grades[]){
	f32 sum = 0;
	for(int i = 0; i < SUBJECTS_NUM; i++)
			sum += grades[i];
	
	return sum;
}

static inline void Std_InvidGPA(f32 sum, uint_32 Full_grade){
	f32 grade = sum / Full_grade;
	if(grade < 60) printf("F");
	else if(grade >= 60 && grade < 65) printf("E");
	else if(grade >= 65 && grade < 67) printf("D");
	else if(grade >= 67 && grade < 70) printf("D+");
	else if(grade >= 70 && grade < 73) printf("C-");
	else if(grade >= 73 && grade < 77) printf("C");
	else if(grade >= 77 && grade < 80) printf("C+");
	else if(grade >= 80 && grade < 83) printf("B-");
	else if(grade >= 83 && grade < 87) printf("B");
	else if(grade >= 87 && grade < 90) printf("B+");
	else if(grade >= 90 && grade < 93) printf("A-");
	else if(grade >= 93 && grade < 97) printf("A");
	else if(grade >= 97) printf("A+");
}