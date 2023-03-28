#pragma once
#include "../Complilation_Object.h"
#include "../Dependent/Type_Object.h"

class Set_Object:public Compilation_Object {
	Data_Type_Object type;
public:
	Set_Object(Position position, Data_Type_Object _type=Data_Type::_void);
	virtual ~Set_Object() = default;
	void set_type(Data_Type_Object _type);
	Data_Type_Object get_type();
};