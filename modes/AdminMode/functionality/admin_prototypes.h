#ifndef _ADMIN_PROTOTYPES_
#define _ADMIN_PROTOTYPES_


/****************************************************************
 * Name :           Admin_uint32UploadDatabase                  *
 * return type :    unsigned int                                *
 * parameters :     void                                        *
 * functionality :  Uploads the database from the array into an *
 *                  allocated pointer in the runtime            *
 ****************************************************************/
uint_32 Admin_uint32UploadDatabases(void);

/****************************************************************
 * Name :           Admin_uint32CheckLogin                      *
 * return type :    unsigned int                                *
 * parameters :     ID, Password                                *
 * functionality :  Checks if the given ID and Password valid   *
 ****************************************************************/
uint_32 Admin_uint32CheckLogin(uint_8* ID, uint_8* Password);

/****************************************************************
 * Name :           Admin_uint32EditPassword                    *
 * return type :    unsigned int                                *
 * parameters :     ID                                          *
 * functionality :  Enables the Admin to edit its login password*
 ****************************************************************/
uint_32 Admin_uint32EditPassword(uint_8* ID);

/****************************************************************
 * Name :           Admin_uint32ViewAllDatabase                 *
 * return type :    unsigned int                                *
 * parameters :     Str                                         *
 * functionality :  Views all the student database              *
 ****************************************************************/
uint_32 Admin_uint32ViewAllDatabase(void);

/****************************************************************
 * Name :           Admin_uint32ViewStudent                     *
 * return type :    unsigned int                                *
 * parameters :     ID                                          *
 * functionality :  views the student record that the admin givs*
 *                  his ID number                               *
 ****************************************************************/
uint_32 Admin_uint32ViewStudent(uint_8* ID);

/****************************************************************
 * Name :           Admin_uint32RemoveAllDatabase               *
 * return type :    unsigned int                                *
 * parameters :     void                                        *
 * functionality :  Removes all the student and users database  *
 ****************************************************************/
uint_32 Admin_uint32RemoveAllDatabase(void);

/****************************************************************
 * Name :           Admin_uint32RemoveStudent                   *
 * return type :    unsigned int                                *
 * parameters :     ID                                          *
 * functionality :  Removes a student and user login info from  *
 *                  their database.                             *
 ****************************************************************/
uint_32 Admin_uint32RemoveStudent(uint_8* ID);

/****************************************************************
 * Name :           Admin_uint32AddStudent                      *
 * return type :    unsigned int                                *
 * parameters :     ID                                          *
 * functionality :  Adds a student record to the database       *
 ****************************************************************/
uint_32 Admin_uint32AddStudent(uint_8* ID);

/****************************************************************
 * Name :           Admin_uint32EditGrades                      *
 * return type :    unsigned int                                *
 * parameters :     ID                                          *
 * functionality :  Enables the Admin to edit the student grades*
 ****************************************************************/
uint_32 Admin_uint32EditGrades(uint_8* ID);

#endif