#include <iostream>
#include <stdexcept>
#include "Compile_message.h"

void raise_error(Position position, std::string error){
	throw std::invalid_argument("Error in " + position.to_string() + error);
}

void show_warning(Position position, std::string warning){
	std::cout << "Warning in " + position.to_string() + warning+'\n';
}
