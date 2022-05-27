#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../std_types/STD_TYPES.h"


sint_32 STDFUNC_sint32GetString(uint_8** Str){
		// allocatting enough memory (at first only) as we don't know
		// how long the string will be.
		*Str = (uint_8*) malloc(35 * sizeof(uint_8));
		
		scanf(" %[^\n]", *Str); // reading the string
		
		// reallocatting a memory that fits the string we has just read
		*Str = realloc(*Str, strlen(*Str) + 1);
		// this return value can be used to ensure that the function worked as we expected
		return 1;
}