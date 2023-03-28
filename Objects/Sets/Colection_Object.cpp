#include "Colection_Object.h"
#include "../../Visitor/Visitor.h"

Colection_Object::Colection_Object(Position position, std::vector<std::shared_ptr<Operative_Object>> _colection):
	Set_Object(position),
	colection(_colection)
{}

void Colection_Object::accept(Visitor &visitor) {
	visitor.visit(*this);
}

std::string Colection_Object::generate_code(){
	std::string code = "colection { ";
	for (auto& element : colection) {
		code += element->generate_code();
	}
	code += "} ";
	return code;
}

std::vector<std::shared_ptr<Operative_Object>>& Colection_Object::get_colection(){
	return colection;
}