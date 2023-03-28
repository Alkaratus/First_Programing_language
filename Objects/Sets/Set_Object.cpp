#include "Set_Object.h"

Set_Object::Set_Object(Position position, Data_Type_Object _type) :Compilation_Object(position), type(_type){}

void Set_Object::set_type(Data_Type_Object _type) {
	type = _type;
}

Data_Type_Object Set_Object::get_type() {
	return type;
}