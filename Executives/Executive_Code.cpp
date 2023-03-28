#include "Executive_Code.h"

Executive_Code::Executive_Code(std::string _text) :
	text(_text),
	index(0)
{}

std::string Executive_Code::get_text(unsigned long long int last_index){
	std::string line;
	if (last_index != -1) {
		line = text.substr(index, last_index - index);
		index = last_index + 1;
	}
	else {
		line = text.substr(index);
		index = text.length();
	}
	return line;
}

std::string  Executive_Code::read_line(){
	return get_text(text.find_first_of('\n', index));
}

std::string Executive_Code::read_word(){
	return get_text(text.find_first_of('\n', index));
}

bool Executive_Code::is_end() const{
	return index == text.length();
}

void Executive_Code::set_position(unsigned long long int position) {
	index = position;
}

unsigned long long int Executive_Code::get_position() {
	return index;
}