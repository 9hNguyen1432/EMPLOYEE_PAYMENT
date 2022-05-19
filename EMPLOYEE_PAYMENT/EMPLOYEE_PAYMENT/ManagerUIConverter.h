#pragma once
#include"IConverter.h"
class ManagerUIConverter : public IConverter
{
public:
	string convert(shared_ptr<void> type);
};

