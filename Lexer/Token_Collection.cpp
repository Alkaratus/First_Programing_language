#include "Token_Collection.h"

Token_Collection::Token_Collection(std::vector<Token> _tokens):
	tokens(_tokens),index(0){}

Token Token_Collection::get_token(){
	auto buffer = index;
	index++;
	if (buffer < tokens.size()) {
		return tokens[buffer];
	}
	return Token(Position());
}

bool Token_Collection::is_end() const{
	return index>= tokens.size();
}
