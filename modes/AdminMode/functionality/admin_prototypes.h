#ifndef _ADMIN_PROTOTYPES_
#define _ADMIN_PROTOTYPES_

uint_32 Admin_uint32UploadDatabase(void);

uint_32 Admin_uint32CheckLogin(uint_8* ID, uint_8* Password);

uint_32 Admin_uint32ViewAllDatabase(void);

uint_32 Admin_uint32ViewStudent(uint_8* ID);

uint_32 Admin_uint32RemoveAllDatabase(void);

uint_32 Admin_uint32RemoveStudent(uint_8* ID);

uint_32 Admin_uint32EditGrades(uint_8* ID);

uint_32 Admin_uint32EditPassword(uint_8* ID);

#endif