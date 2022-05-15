#include <stdio.h>
#include "..\Libraries\STD_TYPES.h"
#include "functionality\app_prototypes.h"


int main(void){
	sint_32 Check_Login;
	while(1){
		Check_Login = App_sint32SystemLogin();
		App_sint32system(Check_Login);
	}
	return 0;
}
