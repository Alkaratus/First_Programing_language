#include "Compare_Conditional_Object.h"
#include "../../../Visitor/Visitor.h"

Compare_Conditional_Object::Compare_Conditional_Object(Position position, std::shared_ptr<Constans_Object> _compared, Operator_Object _operation):
	Inspect_Is_Conditional_Object(position),
	compared(_compared),
	operation(_operation)
{}

void Compare_Conditional_Object::accept(Visitor &visitor){
	visitor.visit(*this);
}

std::string Compare_Conditional_Object::generate_code(){
	return "("+compared->get_type().generate_code()+operation.generate_code() + compared->generate_code() + ") ";
}

Operator_Object Compare_Conditional_Object::get_operator() const {
	return operation;
}

std::shared_ptr<Constans_Object> Compare_Conditional_Object::get_compared() {
	return compared;
}