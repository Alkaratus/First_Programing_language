#include "Operative_Object.h"

Operative_Object::Operative_Object(Position position, bool _l_value, Data_Type_Object _data_type):
	Compilation_Object(position),
	l_value(_l_value),
	data_type(_data_type)
{}

void Operative_Object::set_type(Data_Type_Object _data_type) {
	data_type =_data_type;
}

Data_Type_Object Operative_Object::get_type() {
	return data_type;
}

void Operative_Object::set_l_value(bool _l_value) {
	l_value = _l_value;
}

bool Operative_Object::is_l_value() {
	return l_value;
}