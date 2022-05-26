#ifndef _APP_PROTOTYPES_
#define _APP_PROTOTYPES_

/****************************************************************
 * Name :           App_sint32SystemLogin                       *
 * return type :    signed int                                  *
 * parameters :     void                                        *
 * functionality :  Detect the mode (User or Admin) and checks  *
 *                  if the user or admin login info are correct *
 *                  - returns 1 if admin mode info valid        *
 *                  - returns 2 if user mode info valid         *
 *                  - returns -1 if mode login info isn't valid *
 ****************************************************************/
 sint_32 App_sint32SystemLogin(void);
 
 
/****************************************************************
 * Name :           App_sint32system                            *
 * return type :    signed int                                  *
 * parameters :     EnableAccess                                *
 * functionality :  if the EnableAccess is 1, it means the login*
 *                  info for admin mode is correct, so it gives *
 *                  the admin full access to control the DB     *
 *                  (View, view all, delete, delete all, edit)  *
 *                                                              *
 *                 if the EnableAccess is 2, it means the login *
 *                  info for user mode is correct, so it gives  *
 *                  the user full access to control the DB      *
 *                  (View, edit)                                *
 ****************************************************************/
 sint_32 App_sint32system(sint_32 EnableAccess);
 
#endif