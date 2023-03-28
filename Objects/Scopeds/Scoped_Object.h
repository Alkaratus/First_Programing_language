#pragma once
#include <memory>
#include <vector>
#include "../Complilation_Object.h"
#include "../Composites/Scope_Object.h"

class Scoped_Object :public Compilation_Object {
	Scope_Object scope;
protected:
	std::string generate_statements_code();
public:
	Scoped_Object(Position position);
	virtual ~Scoped_Object() = default;
	void set_scope(Scope_Object _scope);
	Scope_Object& get_scope();
};