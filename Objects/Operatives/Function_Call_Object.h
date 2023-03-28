#pragma once
#include <vector>
#include <memory>
#include "../Dependent/Function_Argument.h"

class Function_Call_Object :public Operative_Object {
	std::string name;
	std::vector<Function_Argument>arguments;
public:
	Function_Call_Object(Position position, std::string name, std::vector<Function_Argument> arguments);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	void set_name(std::string _name);
	std::string get_name();
	std::vector<Function_Argument> &get_arguments();
};