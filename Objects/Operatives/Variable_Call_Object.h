#pragma once
#include "Operative_Object.h"

class Variable_Call_Object :public Operative_Object {
	std::string name;
public:
	Variable_Call_Object(Position position, std::string name);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	std::string get_name();
};