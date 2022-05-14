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
 * parameters :    str(pointer to pointer to unsigned char) *
 * functionality :  it allocates memory for a the string    *
 *                  and reads a string.                     * 
 ************************************************************/
static inline uint_32 Std_Inuint32GetString(uint_8** Str);

/************************************************************
 * Name :           Std_Inuint32CopyRec                     *
 * return type :    unsigned int                            *
 * parameters :    -Ptr_Database : pointer to struct        *
 *                 - O_Ptr_Database: pointer to struct      *
 * functionality :  it allocates memory for a the string    *
 *                  and reads a string.                     * 
 ************************************************************/
static inline uint_32 Std_Inuint32CopyRec(Student_t* Ptr, const Student_t* O_Ptr);

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
static inline void Std_InvidGPA(f32 sum, uint_32 Full_grade);

#endif