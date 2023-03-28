#include "Scoped_Object.h"

Scoped_Object::Scoped_Object(Position position):
	Compilation_Object(position)
{}

std::string Scoped_Object::generate_statements_code() {
	return scope.generate_code();
}

void Scoped_Object::set_scope(Scope_Object _scope) {
	scope = _scope;
}

Scope_Object& Scoped_Object::get_scope(){
	return scope;
}