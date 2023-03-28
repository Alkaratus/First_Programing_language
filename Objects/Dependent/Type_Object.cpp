#include "Type_Object.h"
#include <map>

using std::map, std::string;

namespace Data_Type {
	map<Token::token_type, type> const corresponding_types = {
		{Token::_int,_int},
		{Token::_auto,_auto},
		{Token::_float,_float},
		{Token::_char,_char},
		{Token::_void,_void},
		{Token::_string,_string}
	};

	map<type, string> const type_string{
		{_int,"int"},
		{_float,"float"},
		{_char, "char"},
		{_void, "void"},
		{_string, "string"}
	};

	type convert(Token::token_type token_type) {
		if (corresponding_types.count(token_type)) {
			return corresponding_types.at(token_type);
		}
		return null;
	}

	string to_string(type type) {
		if (type_string.count(type)) {
			return type_string.at(type);
		}
		return "";
	}
}

Data_Type_Object::Data_Type_Object(Token::token_type type):
	concrete(Data_Type::convert(type))
{}

Data_Type_Object::Data_Type_Object(Data_Type::type type):
	concrete(type)
{}

string Data_Type_Object::generate_code(){
	return to_string(concrete)+" ";
}

void Data_Type_Object::set_concrete(Data_Type::type _type) {
	concrete = _type;
}

Data_Type::type Data_Type_Object::get_concrete() const {
	return concrete;
}