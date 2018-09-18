#include "stdafx.h"
#include "Class_Schedule.h"
#include <iostream>


Class_Schedule::Class_Schedule(std::string input_ScheduleName)
{
	string_ScheduleName = input_ScheduleName;
}


Class_Schedule::~Class_Schedule()
{
}

void Class_Schedule::function_ReadSchedule() {
	//outputs the entire schedule, this includes the weeks and days in the weeks.

	std::cout << "Schedule: " << string_ScheduleName << std::endl;
	for (int i = 0; i < vector_Weeks.size(); i++)
	{
		//run read function of every week.
		std::cout << "	Week " << i << ": " << std::endl;
		vector_Weeks[i].function_ReadDays();
	}
}

void Class_Schedule::function_AddWeek() {
	Class_Week obj_Week();
	vector_Weeks.push_back(obj_Week);
}