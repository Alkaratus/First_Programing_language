#pragma once

#include "Source.h"
#include <string>

class Source_String : public Source{
	std::string text;
	unsigned short index;

	char read_char() override;
public:
	Source_String(std::string);
	bool is_end() const override;
};

