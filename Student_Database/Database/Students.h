#ifndef _STUDENTS_
#define _STUDENTS_

/*Number of subjects for the students*/
#define SUBJECTS_NUM 	5

/*Number of the students in the whole database*/
#define STUDENT_NUM	 	20

/*defining the student fields*/
typedef struct{
	uint_8* full_name;			// full name

	uint_8* Std_ID;    			// id as string 
	
	uint_8* gender;    			// gender as string 
	
	uint_16 age;       			// age as unsigned short int
	
	f32 grades[SUBJECTS_NUM];  // strudent grades as array of (STUDENT_NUM) floats
	
}Student_t;


#endif	