#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\..\Libraries\STD_TYPES.h"
#include "..\..\Student_Database\functionality\student_prototypes.h"
#include "..\..\modes\UserMode\functionality\user_prototypes.h"
#include "..\..\modes\AdminMode\functionality\admin_prototypes.h"
#include "app_private.h"

//id enterd in the login
static uint_8* App_ID;

/****************************************************************************************/

 sint_32 App_sint32SystemLogin(void){
	 Admin_sint32UploadDatabases(); // upload the user and student database
	 sint_32 Login_Mode, Login_Check = -1, Login_Counter = 0;
	 
	 /*****************Choose Mode*************************/
	 printf("Login modes : \n (1) Admin Mode \n (2) User Mode\n");
	 printf("Choose Login Mode > ");
	 scanf("%d", &Login_Mode);
	 uint_8* Password;

	 while(Login_Check == -1 && Login_Counter < 3){
		 if(Login_Counter > 0){
			 printf("Your ID or Password is not correct, please try again!\n");
		 }
		 /***************Get Login Info***********************/
		 printf("Enter your ID : ");
		 App_InSint32GetString(&App_ID);
		 printf("Enter your password : ");
		 App_InSint32GetString(&Password);
		 
		 /**************Check Login Info*********************/
		 if(Login_Mode == 1){ // admin mode
			 // check admin login 
			 Login_Check = Admin_sint32CheckLogin(App_ID, Password);
			 Login_Check = ((Login_Check >= 0)? 1:-1);
		 }
		 else if(Login_Mode == 2){ // user mode
			 // Check User login 
			 Login_Check = User_sint32CheckLogin(App_ID, Password);
			 Login_Check = ((Login_Check >= 0)? 2:-1);
		 }
		Login_Counter++;
		
		free(Password); 
	 }
	 
	Password = NULL;
	 
	 if(Login_Check == -1){
		 printf("You can't login any more\n");
	 }
	 
	 return Login_Check;
 }

 
 sint_32 App_sint32system(sint_32 EnableAccess){
	 sint_32 Logout = 0;
	 while(!Logout){
		 if(EnableAccess == 1){
			 App_sint32AdminControl();
		 }
		 else if(EnableAccess == 2){
			 App_sint32UserControl();
		 }
		 Logout = App_sint32SystemLogout();
	 }
	 free(App_ID);
	 return 1;
 }


static sint_32 App_sint32AdminControl(void){
	sint_32 Operation_Number;
	printf(" (1) View a student record\n (2) View a All records\n (3) Remove a student record\n (4) Remove All records\n (5) Add A student\n");
	printf(" (6) Edit Student grades\n (7) Edit Your Password\n");
	printf("Choose an operation > ");
	scanf("%d", &Operation_Number);
	uint_8* Std_Id = NULL;
	switch(Operation_Number){
		case 1: // view a student record
			if(Admin_sint32CheckEmpty() != -1){
				printf("Enter the student ID : ");
				App_InSint32GetString(&Std_Id);
			}
			Admin_sint32ViewStudent(Std_Id);
			if(Std_Id != NULL){
				free(Std_Id);
				Std_Id = NULL;
			}
			break;
		case 2: // view all students
			Admin_sint32ViewAllDatabase();
			break;
		case 3: // remove a student
			printf("Enter the student ID : ");
			App_InSint32GetString(&Std_Id);
			Admin_sint32RemoveStudent(Std_Id);
			if(Std_Id != NULL){
				free(Std_Id);
				Std_Id = NULL;
			}
			break;
		case 4: // remove all database
			Admin_sint32RemoveAllDatabase();
			break;
		case 5: // add a student record
			printf("Enter the student ID : ");
			App_InSint32GetString(&Std_Id);
			Admin_sint32AddStudent(Std_Id);
			if(Std_Id != NULL){
				free(Std_Id);
				Std_Id = NULL;
			}
			break;
		case 6: // edit student grades
			if(Admin_sint32CheckEmpty() != -1){
				printf("Enter the student ID : ");
				App_InSint32GetString(&Std_Id);
			}
			Admin_sint32EditGrades(Std_Id);
			if(Std_Id != NULL){
				free(Std_Id);
				Std_Id = NULL;
			}
			break;
		case 7: // edit the admin password
			Admin_sint32EditPassword(App_ID);
			break;
	}
	return 1;
 }
 
 
static sint_32 App_sint32UserControl(void){
	sint_32 Operation_Number;
	printf(" (1) View a your record\n (2) Edit Student name\n (3) Edit Your Password\n");
	printf("Choose an operation > ");
	scanf("%d", &Operation_Number);
	switch(Operation_Number){
		case 1: // view a student record
			User_sint32ViewStdRec(App_ID);
			break;
		case 2: // edit his name
			User_sint32EditUsername(App_ID);
			break;
		case 3: // edit his password
			User_sint32EditPassword(App_ID);
			break;
	}
	return 1;
 }
 
 
static sint_32 App_sint32SystemLogout(void){
	sint_32 Logout;
	printf("Logout? (0/1) > ");
	scanf("%d", &Logout);
	return Logout;
}

static inline sint_32 App_InSint32GetString(uint_8** Str){
		// allocatting enough memory (at first only) as we don't know
		// how long the string will be.
		*Str = (uint_8*) malloc(35 * sizeof(uint_8));
		
		scanf("%s", *Str); // reading the string
		
		// reallocatting a memory that fits the string we has just read
		*Str = realloc(*Str, strlen(*Str) + 1);
		// this return value can be used to ensure that the function worked as we expected
		return 1;
}