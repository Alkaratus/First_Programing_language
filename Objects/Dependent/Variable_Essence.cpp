#include "Variable_Essence.h"

Variable_Essence::Variable_Essence(Data_Type_Object _data_type, std::string _name, bool _constans):
	data_type(_data_type),
	name(_name),
	constans(_constans)
{}

void Variable_Essence::set_type(Data_Type_Object _data_type){
	data_type = _data_type;
}

Data_Type_Object Variable_Essence::get_type() const{
	return data_type;
}

std::string Variable_Essence::get_name() const{
	return name;
}

bool Variable_Essence::is_constans(){
	return constans;
}

std::string Variable_Essence::generate_code(){
	std::string code = "declare " + data_type.generate_code();
	code += constans ? "const " : "var ";
	code += name + " ";
	return code;
}
