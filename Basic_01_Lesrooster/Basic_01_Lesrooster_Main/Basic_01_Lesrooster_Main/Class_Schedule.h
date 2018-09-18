#pragma once
#include "Class_Week.h"
#include <vector>
#include <string>

class Class_Schedule
{
private:
	std::string string_ScheduleName;
	
public:
	Class_Schedule(std::string input_ScheduleName);
	~Class_Schedule();

	std::vector<Class_Week> vector_Weeks;

	void function_ReadSchedule();
	void function_AddWeek();
};

