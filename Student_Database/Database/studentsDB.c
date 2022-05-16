#include <stdio.h>
#include "../../Libraries/STD_TYPES.h"
#include "studentsDB.h"


Student_t Database_of_Students[STUDENT_NUM] = {
	// full namee              ID     gender       age     grades
	{"Ahmed Khalid", 		"1002321", "Male", 		19, {99, 90, 65, 91, 76}},
	{"Ahmed Basem", 		"1042321", "Male", 		20, {56, 80, 87, 77, 100}},
	{"Ahmed Mahmoud", 		"1032321", "Male", 		23, {76, 70, 95, 65, 99}},
	{"Ahmed Amr", 			"1022321", "Male", 		18, {80, 50, 90, 96, 43}},
	{"Amar Amr", 			"1012321", "Male", 		29, {90, 60, 94, 54, 76}},
	
	{"Roqia Amr", 			"123456", "Female", 	39, {12, 40, 84, 77, 87}},
	{"Amr Mohamed", 		"1062321", "Male", 		16, {77, 30, 84, 87, 65}},
	{"Amr Taha", 			"1072321", "Male", 		17, {74, 20, 74, 80, 54}},
	{"Amr Elsharqwi", 		"1082321", "Male", 		21, {84, 10, 64, 94, 34}},
	{"Amr Mahmoud", 		"1092321", "Male", 		21, {94, 0,  55, 83, 100}},
	
	{"Amr Ibrahem", 		"1102321", "Male", 		22, {98, 21, 90, 81, 45}},
	{"Gharam Esam", 		"1112321", "Female", 	25, {88, 22, 91, 89, 98}},
	{"Khalid Amr", 			"1122321", "Male", 		26, {87, 23, 92, 79, 66}},
	{"Abdo Esam", 			"1132321", "Male", 		42, {67, 24, 93, 69, 90}},
	{"Omar Khalid", 		"1142321", "Male", 		18, {76, 25, 94, 54, 76}},

	{"Ahmed Maged", 		"1152321", "Male", 		23, {55, 87, 69, 53, 84}},
	{"Mohsen Yousef", 		"1162321", "Male", 		24, {75, 56, 74, 93, 73}},
	{"Mahmoud Gad",			"1172321", "Male", 		27, {15, 25, 63, 73, 72}},
	{"Mahmoud Morsy", 		"1182321", "Male", 		28, {43, 98, 53, 64, 76}},
	{"Ahmed Taha", 			"1192321", "Male", 		32, {32, 97, 44, 98, 89}},
};