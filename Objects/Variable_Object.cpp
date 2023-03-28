#include "Variable_Object.h"
#include "../Visitor/Visitor.h"
#include <map>

Variable_Object::Variable_Object(Position position, Variable_Essence _essence, std::shared_ptr<Operative_Object> _value):
	Compilation_Object(position),
	essence(_essence),
	value(_value)
{}

void Variable_Object::accept(Visitor &visitor){
	visitor.visit(*this);
}

std::string Variable_Object::generate_code(){
	return essence.generate_code() + value->generate_code();
}

void Variable_Object::set_essence(Variable_Essence _essence) {
	essence = _essence;
}

Variable_Essence& Variable_Object::get_essence(){
	return essence;
}

std::shared_ptr<Operative_Object> Variable_Object::get_value() {
	return value;
}