#pragma once
#include <vector>
#include <optional>
#include "Complilation_Object.h"
#include "Scopeds/If_Object.h"
#include "Scopeds/Else_Object.h"

class Conditional_Object :public Compilation_Object {
	std::vector<If_Object> if_statements;
	std::optional<Else_Object> else_statement;

public:
	Conditional_Object(Position position,std::vector<If_Object> if_statements, std::optional<Else_Object> else_statement);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	std::vector<If_Object> &get_if_statements();
	std::optional<Else_Object> &get_else_statement();
};