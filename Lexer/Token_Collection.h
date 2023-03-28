#pragma once
#include <vector>
#include "Lexer.h"

class Token_Collection :public Lexer {
	std::vector<Token> tokens;
	unsigned int index;
public:
	Token_Collection(std::vector<Token> _tokens);
	Token get_token() override;
	bool is_end() const override;
};