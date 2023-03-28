#include "Function_Object.h"
#include "../Variable_Object.h"
#include "../../Visitor/Visitor.h"

Function_Object::Function_Object(Position position, Data_Type_Object _returned_type, std::string _name, std::vector<Variable_Essence> _arguments):
	Scoped_Object(position),
	returned_type(_returned_type),
	name(_name),
	arguments(_arguments){}

void Function_Object::accept(Visitor &visitor) {
	visitor.visit(*this);
}

std::string Function_Object::generate_code() {
	std::string code= "FUNCTION " + returned_type.generate_code() + name + " \nARGUMENTS\n";
	for (auto& argument : arguments) {
		code += argument.generate_code() + '\n';
	}
	code += "ARGUMENTS_END\n";
	code += generate_statements_code();
	code += "FUNCTION_END\n\n";
	return code;
}

void Function_Object::set_name(std::string _name) {
	name = _name;
}

std::string  Function_Object::get_name() {
	return name;
}

Data_Type_Object Function_Object::get_type() {
	return returned_type;
}

std::vector<Variable_Essence>& Function_Object::get_arguments() {
	return arguments;
}