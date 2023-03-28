#pragma once
#include "Constans_Object.h"

class Float_Object :public Constans_Object {
	double value;
public:
	Float_Object(Position position, double value);
	std::string generate_code() override;
	value_variant get_value() override;
	void accept(Visitor& visitor) override;
};