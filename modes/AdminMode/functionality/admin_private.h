#ifndef_ADMIN_PRIVATE_
#define _ADMIN_PRIVATE_

/****************************************************************
 * Name :           Admin_InUint32CheckRec                      *
 * return type :    unsigned int                                *
 * parameters :     ID                                          *
 * functionality :  finds the index of the record that contains *
 *                  this id in Admin Database.                  *
 ****************************************************************/
static inline uint_32 Admin_InUint32CheckRec(uint_8* ID);

/****************************************************************
 * Name :           Admin_InUint32GetString                     *
 * return type :    unsigned int                                *
 * parameters :     Str                                         *
 * functionality :  Reads a string                              *
 ****************************************************************/
static inline uint_32 Admin_InUint32GetString(uint_8** Str);

/****************************************************************
 * Name :           Admin_InUint32CopyRec                       *
 * return type :    unsigned int                                *
 * parameters :     NewRec, Rec                                 *
 * functionality :  Copies a record into a new allocated DB     *
 ****************************************************************/
static inline uint_32 Admin_InUint32CopyRec(Admin_t* NewRec, const Admin_t Rec);
#endif