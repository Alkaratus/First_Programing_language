#pragma once
#include "../../Token/Token.h"

namespace Data_Type {
	enum type {
		null,
		_auto, _char, _float, _int, _string, _void
	};
	type convert(Token::token_type token_type);
	std::string to_string(type type);
}

class Data_Type_Object{
	Data_Type::type concrete;
public:
	Data_Type_Object(Token::token_type type);
	Data_Type_Object(Data_Type::type type);
	std::string generate_code();
	void set_concrete(Data_Type::type _type);
	Data_Type::type get_concrete() const;
};
