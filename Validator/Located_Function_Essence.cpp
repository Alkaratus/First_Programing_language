#include "Located_Function_Essence.h"

Located_Function_Essence::Located_Function_Essence(Function_Object& function):
	file_name(function.get_position().get_file().get_file_name()),
	returned_type(function.get_type()),
	name(function.get_name()),
	alt_name(function.get_name()) {
	for (auto argument : function.get_arguments()) {
		arguments_essence.push_back({ argument.get_type() ,argument.is_constans()});
	}
}

Located_Function_Essence::Located_Function_Essence(Function_Object& function, std::string _alt_name):
	file_name(function.get_position().get_file().get_file_name()),
	returned_type(function.get_type()),
	name(function.get_name()),
	alt_name(_alt_name){
	for (auto argument : function.get_arguments()) {
		arguments_essence.push_back({ argument.get_type() ,argument.is_constans() });
	}
}

std::string Located_Function_Essence::get_file_name(){
	return file_name;
}

Data_Type_Object Located_Function_Essence::get_type(){
	return returned_type;
}

std::string Located_Function_Essence::get_name(){
	return name;
}

std::string Located_Function_Essence::get_alt_name(){
	return alt_name;
}

std::vector<std::pair<Data_Type_Object, bool>> Located_Function_Essence::get_arguments_essence(){
	return arguments_essence;
}

