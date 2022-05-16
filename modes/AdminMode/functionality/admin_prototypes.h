#ifndef _ADMIN_PROTOTYPES_
#define _ADMIN_PROTOTYPES_


/****************************************************************
 * Name :           Admin_sint32UploadDatabase                  *
 * return type :    signed int                                  *
 * parameters :     void                                        *
 * functionality :  Uploads the database from the array into an *
 *                  allocated pointer in the runtime            *
 ****************************************************************/
sint_32 Admin_sint32UploadDatabases(void);

/****************************************************************
 * Name :           Admin_sint32CheckEmpty                      *
 * return type :    signed int                                  *
 * parameters :     void                                        *
 * functionality :  Checks if the Database is empty             *
 ****************************************************************/
sint_32 Admin_sint32CheckEmpty(void);

/****************************************************************
 * Name :           Admin_sint32CheckLogin                      *
 * return type :    signed int                                  *
 * parameters :     ID, Password                                *
 * functionality :  Checks if the given ID and Password valid   *
 ****************************************************************/
sint_32 Admin_sint32CheckLogin(uint_8* ID, uint_8* Password);

/****************************************************************
 * Name :           Admin_sint32EditPassword                    *
 * return type :    signed int                                  *
 * parameters :     ID                                          *
 * functionality :  Enables the Admin to edit its login password*
 ****************************************************************/
sint_32 Admin_sint32EditPassword(uint_8* ID);

/****************************************************************
 * Name :           Admin_sint32ViewAllDatabase                 *
 * return type :    signed int                                  *
 * parameters :     Str                                         *
 * functionality :  Views all the student database              *
 ****************************************************************/
sint_32 Admin_sint32ViewAllDatabase(void);

/****************************************************************
 * Name :           Admin_sint32ViewStudent                     *
 * return type :    signed int                                  *
 * parameters :     ID                                          *
 * functionality :  views the student record that the admin givs*
 *                  his ID number                               *
 ****************************************************************/
sint_32 Admin_sint32ViewStudent(uint_8* ID);

/****************************************************************
 * Name :           Admin_sint32RemoveAllDatabase               *
 * return type :    signed int                                  *
 * parameters :     void                                        *
 * functionality :  Removes all the student and users database  *
 ****************************************************************/
sint_32 Admin_sint32RemoveAllDatabase(void);

/****************************************************************
 * Name :           Admin_sint32RemoveStudent                   *
 * return type :    signed int                                  *
 * parameters :     ID                                          *
 * functionality :  Removes a student and user login info from  *
 *                  their database.                             *
 ****************************************************************/
sint_32 Admin_sint32RemoveStudent(uint_8* ID);

/****************************************************************
 * Name :           Admin_sint32AddStudent                      *
 * return type :    signed int                                  *
 * parameters :     ID                                          *
 * functionality :  Adds a student record to the database       *
 ****************************************************************/
sint_32 Admin_sint32AddStudent(uint_8* ID);

/****************************************************************
 * Name :           Admin_sint32EditGrades                      *
 * return type :    signed int                                  *
 * parameters :     ID                                          *
 * functionality :  Enables the Admin to edit the student grades*
 ****************************************************************/
sint_32 Admin_sint32EditGrades(uint_8* ID);

#endif