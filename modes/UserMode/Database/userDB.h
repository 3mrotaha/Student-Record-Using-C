#ifndef	_USER_DATABSE_
#define _USER_DATABSE_

// number of users in the database
#define NUMBER_OF_USERS		10

typedef struct{
	uint_8* User_ID;   // the login id, its the same as the student id
	
	uint_8* Password;  //  the password as string
}User_t;

#endif