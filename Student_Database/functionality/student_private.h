#ifndef _STUDENTS_PRIVATE_
#define _STUDENTS_PRIVATE_
/*
 * these functions are used in the implementation this module only, so it's static
 */


/************************************************************
 * Name:            Std_Insint32Search                      *
 * return type :    signed int                              *
 * parameters :     ID(the student ID)                      *
 * functionality :  it takes the student id, and return     *
 *                  the index of its record in the database * 
 ************************************************************/
static inline sint_32 Std_Insint32Search(uint_8* ID);

/************************************************************
 * Name :           Std_sint32GetString                     *
 * return type :    signed int                              *
 * parameters :    str(pointer to pointer to unsigned char) *
 * functionality :  it allocates memory for a the string    *
 *                  and reads a string.                     * 
 ************************************************************/
static inline sint_32 Std_Insint32GetString(uint_8** Str);

/************************************************************
 * Name :           Std_Insint32CopyRec                     *
 * return type :    signed int                              *
 * parameters :    -Ptr_Database : pointer to struct        *
 *                 - O_Ptr_Database: struct object          *
 * functionality :  it allocates memory for a the string    *
 *                  and reads a string.                     * 
 ************************************************************/
static inline sint_32 Std_Insint32CopyRec(Student_t* Ptr, const Student_t O_Ptr);

/************************************************************
 * Name :           Std_InvidPrintGrades                    *
 * return type :    void                                    *
 * parameters :     grades                                  *
 * functionality :  prints the student grades               *
 ************************************************************/
static inline void Std_InvidPrintGrades(f32 grades[]);

/************************************************************
 * Name :           Std_Inf32TotalGrades                    *
 * return type :    void                                    *
 * parameters :     grades                                  *
 * functionality :  sum the grades and gets the average and *
 *                  percentage                              *
 ************************************************************/
static inline f32 Std_Inf32TotalGrades(f32 grades[]);

/************************************************************
 * Name :           Std_InvidGPA                            *
 * return type :    void                                    *
 * parameters :     sum , Full_grade                        *
 * functionality :  prints the GPA                          *
 ************************************************************/
static inline void Std_InvidGPA(f32 sum, sint_32 Full_grade);

#endif