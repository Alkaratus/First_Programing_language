#pragma once
#include "../Token/Token.h"
class Lexer{
public:
	virtual ~Lexer() = default;
	virtual Token get_token()=0;
	virtual bool is_end() const=0;
};