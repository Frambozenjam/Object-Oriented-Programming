// Basic_01_Lesrooster_Main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Class_Day.h"
#include "Class_Week.h"
#include "Class_Schedule.h"

int main()
{
	Class_Schedule obj_Schedule("MySchedule");
	obj_Schedule.function_AddWeek();
	obj_Schedule.vector_Weeks[0].function_AddDay();
	obj_Schedule.function_ReadSchedule();
    return 0;
}