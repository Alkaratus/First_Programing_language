#pragma once
#include <string>
#include "File.h"
typedef unsigned int uint;

class Position {
	uint line, column;
	File file;
public:
	Position(File file=File(), uint line = 1, uint column = 0);
	Position go_forward(uint number = 1) const;
	Position go_new_line() const;
	uint get_line() const;
	uint get_column() const;
	File get_file() const;
	std::string to_string() const;
};