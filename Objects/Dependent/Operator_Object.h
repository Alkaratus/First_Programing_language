#pragma once
#include "../../Token/Token.h"

namespace Operator_Type {
	enum type {
		null, multiplication, division, modulation,
		summation, subtraction,
		shift_left, shift_right,
		grader_than, less_than, grader_or_equal, less_or_equal,
		not_equal, equal,
		bin_and,
		bin_xor,
		bin_or,
		_and, 
		_or,  
		assign,
		negation,
	};
	type convert(Token::token_type token_type);
	std::string to_string(type type);
}

class Operator_Object {
	Operator_Type::type type;
public:
	Operator_Object(Token::token_type type);
	Operator_Object(Operator_Type::type type);
	Operator_Type::type get_type() const;
	std::string generate_code();
};

