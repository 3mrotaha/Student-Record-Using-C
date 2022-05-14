#ifndef	_USER_PRIVATE_
#define _USER_PRIVATE_

/* NOTE : 
 * THIS FILE CONTAINS THE FUNCTION THAT ONLY WILL BE USED IN THIS MODULE,
 * OTHER MODULES CAN'T SEE IT, AS ALL ITS FUNCTIONS ARE DEFINED AND IMPLEMENTED AS 
 * (STATIC) FUNCTIONS THAT ONLY VISIBLE TO ITS FILE.
 */
 
/****************************************************************
 * Name :           User_InUint32CheckRec                       *
 * return type :    unsigned int                                *
 * parameters :     ID                                          *
 * functionality :  Search for the ID of the user in the databa-*
 *                  -se and return the index of its record      *
 ****************************************************************/
 static inline uint_32 User_InUint32CheckRec(uint_8* ID);
 
/****************************************************************
 * Name :           User_InUint32GetString                      *
 * return type :    unsigned int                                *
 * parameters :     void                                        *
 * functionality :  used to read a string, and fits its memory  *
 *                  to the number of its characters             *
 ****************************************************************/
 static inline uint_32 User_InUint32GetString(uint_8** Str);
 
/****************************************************************
 * Name :           User_InUint32CopyRecord                     *
 * return type :    unsigned int                                *
 * parameters :     NewRec, Rec                                 *
 * functionality :  Copies a record of the database             *
 ****************************************************************/
 static inline uint_32 User_InUint32CopyRecord(User_t* NewRec, const User_t Rec);
 
#endif