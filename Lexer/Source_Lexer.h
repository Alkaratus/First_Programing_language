#pragma once
#include <optional>
#include "../Source/Source.h"
#include "Lexer.h"

using std::optional, std::pair;

class Source_Lexer: public Lexer{
	Source& source;
	char buffer;
	Position curr_position;

	void skip_white_spaces();

	optional<Token> skip_comments_or_create_slash();
	void skip_line_comment();
	void skip_scope_comment();

	optional<Token> create_cost_char();
	char is_correct_char();
	static char is_correct_escape_char(char sign);

	optional<Token> create_const_string();

	optional<Token> create_const_number();
	pair<double, bool> create_integer_value();
	double create_fractional_value();
	long long int convert_to_integer(pair<double, bool> int_value) const;

	optional<Token> create_name_or_keyword();

	optional<Token> create_operator();
		
	optional<Token> create_null();
	void get_char(bool required = true);
public:
	Source_Lexer(Source& source);
	Token get_token() override;
	bool is_end() const override;
};

Token::token_type get_keyword_type(std::string word);
Token::token_type is_operator(char sign);
Token::token_type is_operator(Token::token_type _operator1, Token::token_type _operator2);
	
		