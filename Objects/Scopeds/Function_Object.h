#pragma once
#include <vector>
#include "Scoped_Object.h"
#include "../Variable_Object.h"

class Function_Object :public Scoped_Object {
	Data_Type_Object returned_type;
	std::string name;
	std::vector<Variable_Essence> arguments;
public:
	Function_Object(Position position, Data_Type_Object _returned_type, std::string name, std::vector<Variable_Essence> list_of_arguments);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	void set_name(std::string _name);
	std::string get_name();
	Data_Type_Object get_type();
	std::vector<Variable_Essence> &get_arguments();
};