#pragma once
#include "Constans_Object.h"

class Int_Object :public Constans_Object {
	long long int value;
public:
	Int_Object(Position position, long long int value);
	std::string generate_code() override;
	value_variant get_value() override;
	void accept(Visitor& visitor) override;
};