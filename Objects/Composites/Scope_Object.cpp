#include "Scope_Object.h"
#include "../../Visitor/Visitor.h"

void Scope_Object::add_statement(std::shared_ptr<Compilation_Object> object){
	statements.push_back(object);
}

std::vector<std::shared_ptr<Compilation_Object>>& Scope_Object::get_statements(){
	return statements;
}

void Scope_Object::accept(Visitor& visitor){
	visitor.visit(*this);
}

std::string Scope_Object::generate_code(){
	std::string code;
	for (auto& statement : statements) {
		code += statement->generate_code();
		code += "\n";
	}
	return code;
}
