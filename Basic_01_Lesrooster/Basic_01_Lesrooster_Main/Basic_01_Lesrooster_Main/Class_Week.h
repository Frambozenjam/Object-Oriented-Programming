#pragma once
#include <vector>
#include "Class_Day.h"

class Class_Week
{
private:
public:
	Class_Week();
	~Class_Week();

	std::vector<Class_Day> vector_Days;

	void function_ReadDays();
	void function_AddDay();
};

