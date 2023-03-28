#include "Source_String.h"

Source_String::Source_String(std::string _text) :text(std::move(_text)), index(0), Source() {}

char Source_String::read_char() {
	char sign = '\0';
	if (!is_end()) {
		sign = text[index];
		index++;
	}
	return sign;
}

bool Source_String::is_end() const{
	return index == text.length(); 
}