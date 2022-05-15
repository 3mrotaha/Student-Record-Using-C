#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "..\..\..\Libraries\STD_TYPES.h"
#include "..\..\..\Student_Database\functionality\student_prototypes.h"
#include "..\..\UserMode\functionality\user_prototypes.h"
#include "..\Database\AdminDB.h"
#include "admin_private.h"
#include "admin_prototypes.h"

// array of the records 
extern Admin_t AdminsInfo[NUMBER_OF_ADMINS];


Admin_t *Admin_Database;

/*******************************************************************************************/
uint_32 Admin_uint32UploadDatabase(void);

uint_32 Admin_uint32CheckLogin(uint_8* ID, uint_8* Password);

uint_32 Admin_uint32ViewAllDatabase(void);

uint_32 Admin_uint32ViewStudent(uint_8* ID);

uint_32 Admin_uint32RemoveAllDatabase(void);

uint_32 Admin_uint32RemoveStudent(uint_8* ID);

uint_32 Admin_uint32EditGrades(uint_8* ID);

uint_32 Admin_uint32EditPassword(uint_8* ID);

static inline uint_32 Admin_InUint32CheckRec(uint_8* ID);

static inline uint_32 Admin_InUint32GetString(uint_8** Str);

static inline uint_32 Admin_InUint32CopyRec(Admin_t* NewRec, const Admin_t Rec);