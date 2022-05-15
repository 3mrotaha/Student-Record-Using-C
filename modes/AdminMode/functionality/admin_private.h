#ifndef _ADMIN_PRIVATE_
#define _ADMIN_PRIVATE_

/****************************************************************
 * Name :           Admin_Insint32CheckRec                      *
 * return type :    signed int                                  *
 * parameters :     ID                                          *
 * functionality :  finds the index of the record that contains *
 *                  this id in Admin Database.                  *
 ****************************************************************/
static inline sint_32 Admin_Insint32CheckRec(uint_8* ID);

/****************************************************************
 * Name :           Admin_Insint32GetString                     *
 * return type :    signed int                                  *
 * parameters :     Str                                         *
 * functionality :  Reads a string                              *
 ****************************************************************/
static inline sint_32 Admin_Insint32GetString(uint_8** Str);

/****************************************************************
 * Name :           Admin_Insint32CopyRec                       *
 * return type :    signed int                                  *
 * parameters :     NewRec, Rec                                 *
 * functionality :  Copies a record into a new allocated DB     *
 ****************************************************************/
static inline sint_32 Admin_Insint32CopyRec(Admin_t* NewRec, const Admin_t Rec);
#endif