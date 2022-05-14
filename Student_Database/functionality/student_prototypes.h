#ifndef _STUDENT_PROTOTYPES_H_
#define _STUDENT_PROTOTYPES_H_

/************************************************************
 * Name :           Std_uint32UploadDatabase                *
 * return type :    unsigned int                            *
 * parameters :     void                                    *
 * functionality :  allocatting a memory and upload the DB  *
 *                  to that memory                          *
 ************************************************************/
uint_32 Std_uint32UploadDatabase(void);

/************************************************************
 * Name :           Std_uint32Search                        *
 * return type :    unsigned int                            *
 * parameters :     ID(the student ID)                      *
 * functionality :  it takes the student id, and return     *
 *                  the index of its record in the database * 
 ************************************************************/
uint_32 Std_uint32Search(uint_8* ID);

/************************************************************
 * Name :           Std_uint32Search                        *
 * return type :    unsigned int                            *
 * parameters :     ID(the student ID)                      *
 * functionality :  it takes the student id, and return     *
 *                  the index of its record in the database * 
 ************************************************************/
uint_32 Std_uint32RemoveRec(uint_8* ID);

/************************************************************
 * Name :           Std_uint32AddRec                        *
 * return type :    unsigned int                            *
 * parameters :     ID                                      *
 * functionality :  Adds a new student record into the      *
 *                  database and sort the database          *
 ************************************************************/
uint_32 Std_uint32AddRec(uint_8* ID);

/*************************************************************
 * Name :           std_uint32EditName                       *
 * return type :    unsigned int                             *
 * parameters :     Record_Index : (the student ID)          *
 * functionality :  it search for the record of the given ID *
 *                  and changes the name of this record to a *
 *                  new name taken from the user or admin    * 
 *************************************************************/
uint_32 Std_uint32EditName(uint_32 Record_Index);

/*************************************************************
 * Name :           std_uint32EditName                       *
 * return type :    unsigned int                             *
 * parameters :     Record_Index : (the student ID)          *
 * functionality :  it search for the record of the given ID *
 *                  and changes the name of this record to a *
 *                  new name taken from the user or admin    * 
 *************************************************************/
uint_32 Std_uint32ViewRecord(uint_32 Record_Index);

/***************************************************************
 * Name :           std_uint32EditGrades                       *
 * return type :    unsigned int                               *
 * parameters :     ID(the student ID)                         *
 * functionality :  it takes the student id, looks for its     *
 *                record then change the grades of this record * 
 ***************************************************************/
uint_32 Std_uint32EditGrades(uint_8* ID);

/************************************************************
 * Name :           Std_uint32GetDatabaseLength             *
 * return type :    unsigned int                            *
 * parameters :     ID(the student ID)                      *
 * functionality :  it takes the student id, and return     *
 *                  the index of its record in the database * 
 ************************************************************/
uint_32 Std_uint32GetDatabaseLength(void);

#endif

