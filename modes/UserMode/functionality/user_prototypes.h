#ifndef _USER_PROTOTYPES_
#define _USER_PROTOTYPES_


/****************************************************************
 * Name :           User_uint32UploadDatabase                   *
 * return type :    unsigned int                                *
 * parameters :     void                                        *
 * functionality :  Uploads the database array into a memory    *
 *                  allocated pointer to use and modify this DB *
 *                  in the runtime                              *
 ****************************************************************/
 uint_32 User_uint32UploadDatabase(void);
 
/****************************************************************
 * Name :           User_uint32CheckLogin                       *
 * return type :    unsigned int                                *
 * parameters :     ID, Pswrd                                   *
 * functionality :  Checks the validity of the ID, and password *
 *                  that the user enters in the login page      *
 ****************************************************************/
 uint_32 User_uint32CheckLogin(uint_8* ID, uint_8* Pswrd);
 
/****************************************************************
 * Name :           User_uint32ViewStdRec                       *
 * return type :    unsigned int                                *
 * parameters :     void                                        *
 * functionality :  Based on the ID that the user login with    *
 *	    			it view the record of the student contains  *
 *  				this ID									    *
 ****************************************************************/
 uint_32 User_uint32ViewStdRec(void);
 
/****************************************************************
 * Name :           User_uint32EditUsername                     *
 * return type :    unsigned int                                *
 * parameters :     void                                        *
 * functionality :  Based on the ID that the user login with,   *
 *                  it detects the record of this ID, and enab- *
 *                  les the user to edit his name               *
 ****************************************************************/
 uint_32 User_uint32EditUsername(void);
 
/****************************************************************
 * Name :           User_uint32EditPassword                     *
 * return type :    unsigned int                                *
 * parameters :     void                                        *
 * functionality :  Based on the ID that the user login with,   *
 *                  it detects the record of this ID, and enab- *
 *                  les the user to edit his Login Password     *
 ****************************************************************/
 uint_32 User_uint32EditPassword(void);
 
/****************************************************************
 * Name :           User_uint32AddUser                          *
 * return type :    unsigned int                                *
 * parameters :     ID                                          *
 * functionality :  Adds the user in the given ID to the user   *
 *                  database                                    *  
 ****************************************************************/
 uint_32 User_uint32AddUser(uint_8* ID);
 
/****************************************************************
 * Name :           User_uint32RemoveUser                       *
 * return type :    unsigned int                                *
 * parameters :     ID                                          *
 * functionality :  Removes the user in the given ID from the   *
 *                  user database                               *
 ****************************************************************/
 uint_32 User_uint32RemoveUser(uint_8* ID);
 
#endif