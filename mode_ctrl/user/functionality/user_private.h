#ifndef	_USER_PRIVATE_
#define _USER_PRIVATE_

/* NOTE : 
 * THIS FILE CONTAINS THE FUNCTION THAT ONLY WILL BE USED IN THIS MODULE,
 * OTHER MODULES CAN'T SEE IT, AS ALL ITS FUNCTIONS ARE DEFINED AND IMPLEMENTED AS 
 * (STATIC) FUNCTIONS THAT ONLY VISIBLE TO ITS FILE.
 */
 
/****************************************************************
 * Name :           User_Insint32CheckRec                       *
 * return type :    signed int                                  *
 * parameters :     ID                                          *
 * functionality :  Search for the ID of the user in the databa-*
 *                  -se and return the index of its record      *
 ****************************************************************/
 static inline sint_32 User_Insint32CheckRec(uint_8* ID);
 
 
/****************************************************************
 * Name :           User_Insint32CopyRecord                     *
 * return type :    signed int                                  *
 * parameters :     NewRec, Rec                                 *
 * functionality :  Copies a record of the database             *
 ****************************************************************/
 static inline sint_32 User_Insint32CopyRecord(User_t* NewRec, const User_t Rec);
 
#endif