#include "Variable_Call_Object.h"
#include "../../Visitor/Visitor.h"

Variable_Call_Object::Variable_Call_Object(Position position, std::string _name):Operative_Object(position),name(_name){}

void Variable_Call_Object::accept(Visitor &visitor){
	visitor.visit(*this);
}

std::string Variable_Call_Object::generate_code(){
	return "call_v " + name+" ";
}

std::string Variable_Call_Object::get_name() {
	return name;
}