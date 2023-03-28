#include "Position.h"

Position::Position(File _file, uint _line, uint _column):
	file(_file), 
	line(_line), 
	column(_column) 
{}

Position Position::go_forward(uint number) const {
	return Position(file, line, column +number);
}

Position Position::go_new_line() const {
	return Position(file, line + 1, 0);
}

uint Position::get_line() const{
	return line;
}

uint Position::get_column() const{
	return column;
}

File Position::get_file() const {
	return file;
}

std::string Position::to_string() const {
	return "File: "+ file.get_file_name()+" Line: " + std::to_string(line) + " Column: " + std::to_string(column) + " ";
}

