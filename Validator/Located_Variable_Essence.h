#pragma once
#include "../Objects/Variable_Object.h"
#include "../Objects/Inspect_Conditionals/As_Conditional_Object.h"

class Located_Variable_Essence :public Variable_Essence {
	std::string file_name;
public:
	Located_Variable_Essence(Variable_Object& variable);
	Located_Variable_Essence(As_Conditional_Object& as_conditional);
	Located_Variable_Essence(std::string _file_name, Variable_Essence essence);
	std::string get_file_name();
};