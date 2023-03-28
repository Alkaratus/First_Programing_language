#include "Source_File.h"
#include <filesystem>

Source_File::Source_File(std::string filename) :
	Source(filename),
	file(filename, std::ios::in){
	if (!file.good()) {
		throw std::invalid_argument("Failed to open file");
	}
}

char Source_File::read_char(){
	char sign='\0';
	if (!is_end()) {
		file.read(&sign, 1);
	}
	return sign;
}

bool Source_File::is_end() const{
	return file.eof();
}