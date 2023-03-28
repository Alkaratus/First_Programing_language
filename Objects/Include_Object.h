#pragma once
#include "Complilation_Object.h"

class Include_Object :public Compilation_Object {
	std::string name;
public:
	Include_Object(Position position, std::string name);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	std::string get_name();
};