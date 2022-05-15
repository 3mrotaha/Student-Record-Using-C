#ifndef _USER_PROTOTYPES_
#define _USER_PROTOTYPES_


/****************************************************************
 * Name :           User_sint32UploadDatabase                   *
 * return type :    signed int                                  *
 * parameters :     void                                        *
 * functionality :  Uploads the database array into a memory    *
 *                  allocated pointer to use and modify this DB *
 *                  in the runtime                              *
 ****************************************************************/
 sint_32 User_sint32UploadDatabase(void);
 
/****************************************************************
 * Name :           User_sint32CheckLogin                       *
 * return type :    signed int                                  *
 * parameters :     ID, Pswrd                                   *
 * functionality :  Checks the validity of the ID, and password *
 *                  that the user enters in the login page      *
 ****************************************************************/
 sint_32 User_sint32CheckLogin(uint_8* ID, uint_8* Pswrd);
 
/****************************************************************
 * Name :           User_sint32ViewStdRec                       *
 * return type :    signed int                                  *
 * parameters :     ID                                          *
 * functionality :  Based on the ID that the user login with    *
 *	    			it view the record of the student contains  *
 *  				this ID									    *
 ****************************************************************/
 sint_32 User_sint32ViewStdRec(uint_8* ID);
 
/****************************************************************
 * Name :           User_sint32EditUsername                     *
 * return type :    signed int                                  *
 * parameters :     ID                                          *
 * functionality :  Based on the ID that the user login with,   *
 *                  it detects the record of this ID, and enab- *
 *                  les the user to edit his name               *
 ****************************************************************/
 sint_32 User_sint32EditUsername(uint_8* ID);
 
/****************************************************************
 * Name :           User_sint32EditPassword                     *
 * return type :    signed int                                  *
 * parameters :     ID                                          *
 * functionality :  Based on the ID that the user login with,   *
 *                  it detects the record of this ID, and enab- *
 *                  les the user to edit his Login Password     *
 ****************************************************************/
 sint_32 User_sint32EditPassword(uint_8* ID);
 
/****************************************************************
 * Name :           User_sint32AddUser                          *
 * return type :    signed int                                  *
 * parameters :     ID                                          *
 * functionality :  Adds the user in the given ID to the user   *
 *                  database                                    *  
 ****************************************************************/
 sint_32 User_sint32AddUser(uint_8* ID);
 
/****************************************************************
 * Name :           User_sint32RemoveUser                       *
 * return type :    signed int                                  *
 * parameters :     ID                                          *
 * functionality :  Removes the user in the given ID from the   *
 *                  user database                               *
 ****************************************************************/
 sint_32 User_sint32RemoveUser(uint_8* ID);

/****************************************************************
 * Name :           User_sint32RemoveAllUsers                   *
 * return type :    signed int                                  *
 * parameters :     void                                        *
 * functionality :  Removes the user in the given ID from the   *
 *                  user database                               *
 ****************************************************************/
 sint_32 User_sint32RemoveAllUsers(void);
#endif