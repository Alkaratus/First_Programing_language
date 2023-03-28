#include "Operation_Object.h"
#include "../../Visitor/Visitor.h"

Operation_Object::Operation_Object(Position position, std::shared_ptr<Operative_Object> _operative_1, Operator_Object __operator, std::shared_ptr<Operative_Object> _operative_2):
Operative_Object(position), 
operative_1(_operative_1), 
_operator(__operator), 
operative_2(_operative_2)
{}

void Operation_Object::accept(Visitor &visitor) {
	visitor.visit(*this);
}

std::string Operation_Object::generate_code() {
	return "("+operative_1->get_type().generate_code()+ operative_1->generate_code() + _operator.generate_code() + operative_2->generate_code() + ") ";
}

std::shared_ptr<Operative_Object>& Operation_Object::get_first_operative() {
	return operative_1;
}

std::shared_ptr<Operative_Object>& Operation_Object::get_second_operative() {
	return operative_2;
}

Operator_Object Operation_Object::get_operator() {
	return _operator;
}