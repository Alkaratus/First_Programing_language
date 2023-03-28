#pragma once
#include <vector>
#include <memory>
#include "../Complilation_Object.h"

class Scope_Object {
	std::vector<std::shared_ptr<Compilation_Object>>statements;
public:
	void add_statement(std::shared_ptr<Compilation_Object> object);
	std::vector<std::shared_ptr<Compilation_Object>>& get_statements();
	void accept(Visitor& visitor);
	std::string generate_code();
};