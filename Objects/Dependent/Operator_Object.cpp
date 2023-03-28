#include <map>
#include "Operator_Object.h"

using std::map, std::string;

namespace Operator_Type {
	map<Token::token_type, type> const corresponding_types = {
		{Token::negation,negation},
		{Token::grader_than,grader_than},
		{Token::less_than,less_than},
		{Token::assign,assign},
		{Token::bin_or,bin_or},
		{Token::bin_and,bin_and},
		{Token::bin_xor,bin_xor},
		{Token::summation,summation},
		{Token::subtraction,subtraction},
		{Token::multiplication,multiplication},
		{Token::division,division},
		{Token::modulation,modulation},
		{Token::not_equal,not_equal},
		{Token::equal,equal},
		{Token::grader_or_equal,grader_or_equal},
		{Token::less_or_equal,less_or_equal},
		{Token::_and,_and},
		{Token::_or,_or},
		{Token::shift_left,shift_left},
		{Token::shift_right,shift_right}
	};

	map<type, std::string> const type_string = {
		{negation,"!"},
		{grader_than,">"},
		{less_than,"<"},
		{assign,"="},
		{bin_or,"|"},
		{bin_and,"&"},
		{bin_xor,"^"},
		{summation,"+"},
		{subtraction,"-"},
		{multiplication,"*"},
		{division,"/"},
		{modulation,"%"},
		{not_equal,"!="},
		{equal,"=="},
		{grader_or_equal,">="},
		{less_or_equal,"<="},
		{_and,"&&"},
		{_or,"||"},
		{shift_left,"<<"},
		{shift_right,"||"}
	};

	Operator_Type::type Operator_Type::convert(Token::token_type token_type) {
		if (corresponding_types.count(token_type)) {
			return corresponding_types.at(token_type);
		}
		return Operator_Type::null;
	}

	string Operator_Type::to_string(type type) {
		if (type_string.count(type)) {
			return type_string.at(type);
		}
		return "";
	}
}

Operator_Object::Operator_Object(Token::token_type _type):
	type(Operator_Type::convert(_type))
{}

Operator_Object::Operator_Object(Operator_Type::type _type):
	type(_type)
{}

Operator_Type::type Operator_Object::get_type() const{
	return type;
}

std::string Operator_Object::generate_code(){
	return Operator_Type::to_string(type)+' ';
}


