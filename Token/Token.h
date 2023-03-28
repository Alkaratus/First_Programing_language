#pragma once
#include <string>
#include "../Overall/Position.h"
#include <variant>

typedef std::variant<std::string, double, long long, char> value_variant;

class Token {
public:
	enum token_type {
		//Operatory jednoargumentowe, które mog¹ byæ czêœci¹ dwuelementowych
		negation = 1, grader_than = 2, less_than = 3, assign = 4, bin_or = 5, bin_and = 6,
		//Operatory jednoargumentowe 
		bin_xor = 7,
		summation = 8, subtraction = 9, multiplication = 10, division = 11, modulation = 12, 
		open_bracket = 13, close_bracket = 14, open_square = 15, close_square = 16, open_buckle = 17, close_buckle = 18,
		hash = 19, question_mark = 20, colon = 21, semicolon = 22, comma = 23, dot = 24,
		//Operatory dwuargumentowe
		not_equal = 25, equal = 26, grader_or_equal = 27, less_or_equal = 28, _and = 29, _or = 30,
		shift_left = 31, shift_right = 32,
		//Typy_Danych
		_auto = 33, _char = 34, _int = 35, _float = 36, _string = 37,
		//Inne s³owa kluczowe jêzyka
		include = 38, _if = 39, _else = 40, _while = 41, _void = 42, _return = 43, var = 44, _static = 45, in = 46, inspect = 47, is = 48, as = 49, name = 50,
		//Sta³e
		const_char = 51, const_string = 52, const_int = 53, const_float = 54,
		null = 0
	};
private:
	value_variant value;
	Position position;
	token_type type;
public:
	static const auto
		LAST_DOUBLEABLE_OPERATOR = bin_and,
		LAST_SINGLE_OPERATOR = modulation,
		FIRST_DOUBLE_OPERATOR = not_equal,
		LAST_DOUBLE_OPERATOR = shift_right,
		FIRST_VARIABLE_TYPE = _char,
		LAST_VARIABLE_TYPE = _string, 
		FIRST_CONSTANS = const_char;

	Token(Position position=Position(), value_variant value = '\0', token_type token_type = null);
	value_variant get_value() const;
	Position get_position() const;
	token_type get_type() const;
	bool is_variable_type() const;
	bool is_operator_type() const;
	bool is_data() const;
};
	


