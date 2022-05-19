#pragma once
#include"IConverter.h"
class DailyEmployeeUIConverter: public IConverter
{
public:
	string convert(shared_ptr<void> type);
};

