#pragma once
#include <memory>
#include "../Complilation_Object.h"
#include "../Dependent/Type_Object.h"

class Operative_Object: public Compilation_Object{
	Data_Type_Object data_type;
	bool l_value; 
public:
	Operative_Object(Position position, bool l_value = true, Data_Type_Object data_type = Data_Type_Object(Data_Type::_auto));
	virtual ~Operative_Object() = default;
	void set_type(Data_Type_Object type);
	Data_Type_Object get_type();
	void set_l_value(bool _l_value);
	bool is_l_value();
	
};