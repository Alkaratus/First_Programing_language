#pragma once
#include <fstream>
#include "Source.h"

class Source_File:public Source{
	std::fstream file;
	char read_char() override;
public:
	Source_File(std::string filename);
	bool is_end() const override;
};

