#pragma once
#include "Constans_Object.h"

class String_Object :public Constans_Object {
	std::string value;
public:
	String_Object(Position position, std::string value);
	std::string generate_code() override;
	value_variant get_value() override;
	void accept(Visitor& visitor) override;
};