#pragma once
#include "Inspect_Conditional_Object.h"
#include "../Dependent/Type_Object.h"

class As_Conditional_Object :public Inspect_Conditional_Object {
	std::string name;
	Data_Type_Object type;
public:
	As_Conditional_Object(Position position, std::string name, Data_Type_Object type);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	std::string get_name();
	Data_Type_Object get_type();
};