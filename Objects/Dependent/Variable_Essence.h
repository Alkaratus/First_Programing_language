#pragma once
#include "Type_Object.h"

class Variable_Essence {
	Data_Type_Object data_type;
	std::string name;
	bool constans;
public:
	Variable_Essence(Data_Type_Object data_type,std::string name,bool constans);
	void set_type(Data_Type_Object _data_type);
	Data_Type_Object get_type() const;
	std::string get_name() const;
	bool is_constans();
	std::string generate_code();
};