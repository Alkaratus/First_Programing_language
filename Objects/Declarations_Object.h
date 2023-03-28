#pragma once
#include <vector>
#include "Complilation_Object.h"
#include "Variable_Object.h"

class Declarations_Object :public Compilation_Object {
	std::vector<Variable_Object>declarated_variables;
public:
	Declarations_Object(Position position, std::vector<Variable_Object> _declarated_variables);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	std::vector<Variable_Object> &get_declarations();
};