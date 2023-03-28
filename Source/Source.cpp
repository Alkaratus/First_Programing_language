#include "Source.h"
#include <cctype>

Source::Source(std::string file_name):
	position(File(file_name))
{}

char Source::get_char() {
	char sign = '\0';
	position=position.go_forward();
	sign = read_char();
	if (sign == '\t') {
		position=position.go_forward(TAB_SIZE);
	}
	else if (sign == '\n') {
		position = position.go_new_line();
	}
	return sign;
}

Position Source::get_position() const{
	return position;
}

void Source::set_position(Position _position){
	position = _position;
}
