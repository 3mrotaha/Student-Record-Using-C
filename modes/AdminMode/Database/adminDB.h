#ifndef _ADMINS_DATABASE_
#define _ADMINS_DATABASE_

// number of admins in the database
#define NUMBER_OF_ADMINS	5

// defining the admin record
typedef struct{
	uint_8* full_name;
	uint_8* admin_ID;
	uint_8* password;
}Admin_t;

#endif