#ifndef _STUDENT_PROTOTYPES_H_
#define _STUDENT_PROTOTYPES_H_

/************************************************************
 * Name :           Std_sint32UploadDatabase                *
 * return type :    unsigned int                            *
 * parameters :     void                                    *
 * functionality :  allocatting a memory and upload the DB  *
 *                  to that memory                          *
 ************************************************************/
sint_32 Std_sint32UploadDatabase(void);

/************************************************************
 * Name :           Std_sint32Search                        *
 * return type :    unsigned int                            *
 * parameters :     ID(the student ID)                      *
 * functionality :  it takes the student id, and return     *
 *                  the index of its record in the database * 
 ************************************************************/
sint_32 Std_sint32Search(uint_8* ID);

/************************************************************
 * Name :           Std_sint32RemoveRec                     *
 * return type :    unsigned int                            *
 * parameters :     ID(the student ID)                      *
 * functionality :  it takes the student id, removes the    *
 *                  student record of this id               *
 ************************************************************/
sint_32 Std_sint32RemoveRec(uint_8* ID);

/************************************************************
 * Name :           Std_sint32RemoveAll                     *
 * return type :    unsigned int                            *
 * parameters :     ID(the student ID)                      *
 * functionality :  frees the database                      * 
 ************************************************************/
sint_32 Std_sint32RemoveAll(void);

/************************************************************
 * Name :           Std_sint32AddRec                        *
 * return type :    unsigned int                            *
 * parameters :     ID  (new ID)                            *
 * functionality :  Adds a new student record into the      *
 *                  database                                *
 ************************************************************/
sint_32 Std_sint32AddRec(uint_8* ID);

/*************************************************************
 * Name :           std_sint32EditName                       *
 * return type :    unsigned int                             *
 * parameters :     Record_Index : (the student ID)          *
 * functionality :  it search for the record of the given ID *
 *                  and changes the name of this record to a *
 *                  new name taken from the user or admin    * 
 *************************************************************/
sint_32 Std_sint32EditName(sint_32 Record_Index);

/*************************************************************
 * Name :           std_sint32EditName                       *
 * return type :    unsigned int                             *
 * parameters :     Record_Index : (the student ID)          *
 * functionality :  it search for the record of the given ID *
 *                  and changes the name of this record to a *
 *                  new name taken from the user or admin    * 
 *************************************************************/
sint_32 Std_sint32ViewRecord(sint_32 Record_Index);

/*************************************************************
 * Name :           Std_sint32ViewBrief                      *
 * return type :    unsigned int                             *
 * parameters :     Record_Index : (the student Record)      *
 * functionality :  Views a Brief about the student          *
 *************************************************************/
sint_32 Std_sint32ViewBrief(sint_32 Record_Index);

/***************************************************************
 * Name :           std_sint32EditGrades                       *
 * return type :    unsigned int                               *
 * parameters :     ID(the student ID)                         *
 * functionality :  it takes the student id, looks for its     *
 *                record then change the grades of this record * 
 ***************************************************************/
sint_32 Std_sint32EditGrades(uint_8* ID);

/************************************************************
 * Name :           Std_sint32GetDatabaseLength             *
 * return type :    unsigned int                            *
 * parameters :     ID(the student ID)                      *
 * functionality :  it takes the student id, and return     *
 *                  the index of its record in the database * 
 ************************************************************/
sint_32 Std_sint32GetDatabaseLength(void);

#endif

