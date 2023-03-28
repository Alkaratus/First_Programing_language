#include "Inspect_Object.h"
#include "../Visitor/Visitor.h"

Inspect_Object::Inspect_Object(Position position, std::shared_ptr<Operative_Object> _inspected, std::vector<std::shared_ptr<Inspect_Option_Object>> _options):
	Compilation_Object(position),
	inspected(_inspected),
	options(_options)
{}


void Inspect_Object::accept(Visitor &visitor) {
	visitor.visit(*this);
}

std::string Inspect_Object::generate_code() {
	std::string code="INSPECT ("+inspected->get_type().generate_code()+ inspected->generate_code() + ")\n";
	for (auto& option : options) {
		code+=option->generate_code();
	}
	code += "INSPECT_END\n";
	return code;
}

std::shared_ptr<Operative_Object> Inspect_Object::get_inspected() {
	return inspected;
}

std::vector<std::shared_ptr<Inspect_Option_Object>> &Inspect_Object::get_options() {
	return options;
}