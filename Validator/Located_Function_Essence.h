#pragma once
#include "../Objects/Scopeds/Function_Object.h"

class Located_Function_Essence {
	std::string file_name;
	Data_Type_Object returned_type;
	std::string name;
	std::string alt_name;
	std::vector <std::pair<Data_Type_Object, bool>>arguments_essence;
public:
	Located_Function_Essence(Function_Object& function);
	Located_Function_Essence(Function_Object& function, std::string alt_name);
	std::string get_file_name();
	Data_Type_Object get_type();
	std::string get_name();
	std::string get_alt_name();
	std::vector <std::pair<Data_Type_Object, bool>>get_arguments_essence();
};