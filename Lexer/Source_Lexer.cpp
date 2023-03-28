#include "Source_Lexer.h"
#include <stdexcept>
#include <map>
#include <iostream>
#include <cmath>
#include <functional>
#include <limits>

using std::map;

const map<char, char> escape_chars = { 
	{'a','\a'},
	{'b','\b'},
	{'f','\f'},
	{'n','\n'},
	{'r','\r'},
	{'t','\t'},
	{'v','\v'},
	{'\'','\''},
	{'\"','\"'},
	{'\?','\?'},
	{'\\','\\'} 
};

const map<std::string, Token::token_type> keyward_types = {
	{"auto",Token::_auto},
	{"char",Token::_char},
	{"int",Token::_int},
	{"float",Token::_float},
	{"string",Token::_string},
	{"include",Token::include},
	{"if",Token::_if},
	{"else",Token::_else},
	{"while",Token::_while},
	{"void",Token::_void},
	{"return",Token::_return},
	{"var",Token::var},
	{"static",Token::_static},
	{"in",Token::in},
	{"inspect",Token::inspect},
	{"is",Token::is},
	{"as",Token::as} 
};

const map<char, Token::token_type>single_operators_types = {
	{'!',Token::negation},
	{'<',Token::less_than},
	{'=',Token::assign},
	{'>',Token::grader_than},
	{'|',Token::bin_or},
	{'&',Token::bin_and},
	{'^',Token::bin_xor},
	{'(',Token::open_bracket},
	{')',Token::close_bracket},
	{'[',Token::open_square},
	{']',Token::close_square},
	{'{',Token::open_buckle},
	{'}',Token::close_buckle},
	{'+',Token::summation},
	{'-',Token::subtraction},
	{'*',Token::multiplication},
	{'/',Token::division},
	{'%',Token::modulation},
	{'#',Token::hash},
	{'?',Token::question_mark},
	{':',Token::colon},
	{';',Token::semicolon},
	{',',Token::comma}
};

const Token::token_type double_operators_types[][3] = {
	{Token::negation,Token::assign,Token::not_equal},
	{Token::assign,Token::assign,Token::equal},
	{Token::less_than,Token::assign,Token::less_or_equal},
	{Token::grader_than,Token::assign,Token::grader_or_equal},
	{Token::bin_and,Token::bin_and,Token::_and},
	{Token::bin_or,Token::bin_or,Token::_or},
	{Token::grader_than,Token::grader_than,Token::shift_right},
	{Token::less_than,Token::less_than,Token::shift_left}
};


Source_Lexer::Source_Lexer(Source& _source):source(_source),buffer(0),curr_position(){}

Token Source_Lexer::get_token(){
	auto methods = {
		&Source_Lexer::skip_comments_or_create_slash,
		&Source_Lexer::create_cost_char,
		&Source_Lexer::create_const_string,
		&Source_Lexer::create_const_number,
		&Source_Lexer::create_name_or_keyword,
		&Source_Lexer::create_operator,
		&Source_Lexer::create_null
	};
	skip_white_spaces();
	curr_position = source.get_position();
	for (auto func : methods) {
		if (auto token = std::invoke(func, this)) {
			return *token;
		}
	}
	raise_error(source.get_position(), "Unknown character");
}

bool Source_Lexer::is_end() const{
	return source.is_end();
}

void Source_Lexer::skip_white_spaces(){
	while ((isspace(buffer) || buffer == '\0') && !source.is_end()) {
		get_char(false);
	}
	if (isspace(buffer) && source.is_end()) {
		buffer = '\0';
	}
}


optional<Token> Source_Lexer::skip_comments_or_create_slash() {
	while (buffer == '/') {
		get_char(false);
		if (buffer == '/') {
			skip_line_comment();
		}
		else if (buffer == '*') {
			skip_scope_comment();
		}
		else {
			return Token(curr_position, '\0', Token::division);
		}
		skip_white_spaces();
	}
	curr_position = source.get_position();
	return {};
}

void Source_Lexer::skip_line_comment(){
	do {
		get_char(false);
	} while (buffer !='\n' && buffer!='\0');
	buffer = '\0';
}

void Source_Lexer::skip_scope_comment(){
	auto end_scope = false;
	do {
		get_char();
		if (buffer == '*') {
			get_char();
			if (buffer == '/') {
				end_scope = true;
			}
		}
	} while (!end_scope);
	buffer = '\0';
}


optional<Token> Source_Lexer::create_cost_char() {
	if (buffer != '\'') {
		return {};
	}
	auto token_value = is_correct_char();
	get_char();
	if (buffer != '\'') {
		raise_error(source.get_position(),"unexpected sign, expected \'!");
	}
	buffer = '\0';
	return Token(curr_position, token_value, Token::const_char);
}

char Source_Lexer::is_correct_char() {
	std::string returned_char;
	get_char();
	if (buffer == '\\') {
		get_char();
		buffer = is_correct_escape_char(buffer);
	}
	return buffer;
}

char Source_Lexer::is_correct_escape_char(char sign) {
	if (escape_chars.count(sign)) {
		return escape_chars.at(sign);
	}
	return sign;
}


optional<Token> Source_Lexer::create_const_string() {
	if (buffer != '\"') {
		return {};
	}
	std::string value = "";
	auto next_char = is_correct_char();
	while (next_char != '\"') {
		value += next_char;
		next_char = is_correct_char();
	}
	buffer = '\0';
	return Token(curr_position, value, Token::token_type::const_string);
}


optional<Token> Source_Lexer::create_const_number() {
	bool overflow = false;
	if (!isdigit(buffer)) {
		return {};
	}
	pair<double, bool> value = { 0,false };
	if (buffer != '0') {
		value = create_integer_value();
	}
	else {
		get_char(false);
	}
	if (buffer == '.') {
		get_char();
		if (!isdigit(buffer)) {
			raise_error(source.get_position(),"unexpected sign, expected digit");
		}
		value.first+=create_fractional_value();
		return Token(curr_position, value.first, Token::const_float);
	}
	return Token(curr_position, convert_to_integer(value), Token::const_int);
}

pair<double, bool> Source_Lexer::create_integer_value(){
	double value = (buffer - '0');
	get_char(false);
	bool overflow = false;
	while (isdigit(buffer)) {
		value *= 10;
		value += (buffer - '0');
		get_char(false);
        if (value > static_cast<double>(std::numeric_limits<long long int>::max())) {
			overflow = true;
		}
	};
	return std::make_pair(value,overflow);
}

double Source_Lexer::create_fractional_value(){
	int i = 0;
	double value =0;
	while (isdigit(buffer)) {
		value *= 10;
		value += (buffer - '0');
		i++;
		get_char(false);
	};
	return round(value)/pow(10, i);
}

long long int Source_Lexer::convert_to_integer(pair<double, bool> int_value) const{
	if (int_value.second) {
		show_warning(curr_position, "Integer overflow");
		return std::numeric_limits<long long int>::max();
	}
	return static_cast<long long int>(int_value.first);
}


optional<Token> Source_Lexer::create_name_or_keyword() {
	if ((!isalpha(buffer)) && buffer != '_') {
		return {};
	}
	std::string value;
	value += buffer;
	get_char(false);
	while (isalnum(buffer) || buffer == '_') {
		value += buffer;
		get_char(false);
	}
	return Token(curr_position, value, get_keyword_type(value));
}

optional<Token> Source_Lexer::create_operator() {
	auto _operator = is_operator(buffer);
	if (!_operator) {
		return {};
	}
	if (_operator <= Token::LAST_DOUBLEABLE_OPERATOR) {
		get_char(false);
		auto is_sign_operator = is_operator(buffer);
		if (is_sign_operator && buffer != '-') {
			_operator = is_operator(_operator, is_sign_operator);
			if (!_operator) {
				raise_error(curr_position, "invalid operator");
			}
			buffer = '\0';
		}
	}
	else {
		buffer = '\0';
	}
	return Token(curr_position, '\0', _operator);
}

optional<Token> Source_Lexer::create_null(){
	if (buffer == '\0') {
		return Token(source.get_position());
	}
	return {};
}

void Source_Lexer::get_char(bool required) {
	buffer=source.get_char();
	if (required && buffer == '\0') {
		raise_error(source.get_position(), "unexpected end of file");
	}

}

Token::token_type get_keyword_type(std::string word){
	if (keyward_types.count(word)) {
		return keyward_types.at(word);
	}
	return Token::token_type::name;
}

Token::token_type is_operator(char sign) {
	if (single_operators_types.count(sign)) {
		return single_operators_types.at(sign);
	}
	return Token::token_type::null;
}

Token::token_type is_operator(Token::token_type operator1, Token::token_type operator2) {
	for (auto& [first, second, third] : double_operators_types) {
		if (std::tie(first, second) == std::tie(operator1, operator2)) {
			return third;
		}
	}

	return Token::token_type::null;
}
