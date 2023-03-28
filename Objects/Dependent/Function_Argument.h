#pragma once
#include <memory>
#include "../Operatives/Operative_Object.h"
class Function_Argument {
	bool copy;
	std::shared_ptr<Operative_Object>value;
public:
	Function_Argument(bool _copy, std::shared_ptr<Operative_Object>_value);
	bool is_copy();
	std::shared_ptr<Operative_Object> get_value();
};