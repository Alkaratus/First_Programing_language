#include "Token.h"
using namespace std;

Token::Token(Position _position, value_variant _value, token_type _token_type) :
	position(_position), type(_token_type),value(_value) {
}

value_variant Token::get_value() const{
	return value;
}

Position Token::get_position() const{ return position; }

Token::token_type Token::get_type() const{ return type; }

bool Token::is_variable_type() const {
	return type >= FIRST_VARIABLE_TYPE && type <= LAST_VARIABLE_TYPE;
}

bool Token::is_operator_type() const {
	return (type >= null && type <= LAST_SINGLE_OPERATOR) || (type >= FIRST_DOUBLE_OPERATOR && type <= LAST_DOUBLE_OPERATOR);
}

bool Token::is_data() const {
	return type >= FIRST_CONSTANS;
}