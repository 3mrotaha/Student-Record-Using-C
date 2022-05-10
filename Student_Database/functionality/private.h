#ifndef _STUDENTS_PRIVATE_
#define _STUDENTS_PRIVATE_
/*
 * these functions are used in the implementation this module only, so it's static
 */


/************************************************************
 * Name:            Std_Inuint32Search                      *
 * return type :    unsigned int                            *
 * parameters :     ID(the student ID)                      *
 * functionality :  it takes the student id, and return     *
 *                  the index of its record in the database * 
 ************************************************************/
static inline uint_32 Std_Inuint32Search(uint_8* ID);

/************************************************************
 * Name :           Std_uint32GetString                     *
 * return type :    unsigned int                            *
 * parameters :     str(pointer to unsigned char)           *
 * functionality :  it allocates memory for a the string    *
 *                  and reads a string.                     * 
 ************************************************************/
static inline uint_32 Std_Inuint32GetString(uint_8* Str);

/************************************************************
 * Name :           Std_uint32GetDatabaseLength             *
 * return type :    unsigned int                            *
 * parameters :     ID(the student ID)                      *
 * functionality :  it takes the student id, and return     *
 *                  the index of its record in the database * 
 ************************************************************/
static inline uint_32 Std_Inuint32GetDatabaseLength();


#endif