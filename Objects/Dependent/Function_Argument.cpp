#include "Function_Argument.h"

Function_Argument::Function_Argument(bool _copy, std::shared_ptr<Operative_Object>_value) :
	copy(_copy), value(_value)
{}

bool Function_Argument::is_copy(){
	return copy;
}

std::shared_ptr<Operative_Object> Function_Argument::get_value(){
	return value;
}
