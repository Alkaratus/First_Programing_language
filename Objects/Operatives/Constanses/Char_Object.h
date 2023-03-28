#pragma once
#include "Constans_Object.h"

class Char_Object :public Constans_Object {
	char value;
public:
	Char_Object(Position position, char value);
	std::string generate_code() override;
	value_variant get_value() override;
	void accept(Visitor& visitor) override;
};