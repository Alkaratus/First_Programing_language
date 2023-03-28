#include "Function_Call_Object.h"
#include "../../Visitor/Visitor.h"

Function_Call_Object::Function_Call_Object(Position position, std::string _name, std::vector<Function_Argument>_arguments):
Operative_Object(position),name(_name), arguments(_arguments){
}

void Function_Call_Object::accept(Visitor &visitor) {
	visitor.visit(*this);
}

std::string Function_Call_Object::generate_code() {
	auto code = "call_f " + name + " ( ";
	for (auto& argument : arguments) {
		if (argument.is_copy()) {
			code += "# ";
		}
		code += argument.get_value()->generate_code();
	}
	code += ") ";
	return code;
}

void Function_Call_Object::set_name(std::string _name) {
	name = _name;
}

std::string Function_Call_Object::get_name() {
	return name;
}

std::vector<Function_Argument>& Function_Call_Object::get_arguments() {
	return arguments;
}