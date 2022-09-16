#ifndef _APP_PRIVATE_
#define _APP_PRIVATE_

/****************************************************************
 * Name :           App_sint32AdminControl                      *
 * return type :    signed int                                  *
 * parameters :     void                                        *
 * functionality :  it gives the admin full access to control   *
 *                  the DB (View, view all, delete, delete all, *
 *                   edit)                                      *
 ****************************************************************/
static sint_32 App_sint32AdminControl(void);

/****************************************************************
 * Name :           App_sint32UserControl                       *
 * return type :    signed int                                  *
 * parameters :     void                                        *
 * functionality :  gives the User full access to control the DB*
 *                  (View, Edit)                                *
 ****************************************************************/
static sint_32 App_sint32UserControl(void);

/****************************************************************
 * Name :           App_sint32SystemLogout                      *
 * return type :    signed int                                  *
 * parameters :     void                                        *
 * functionality :  Logs out from the system                    *
 ****************************************************************/
static sint_32 App_sint32SystemLogout(void);
  
#endif