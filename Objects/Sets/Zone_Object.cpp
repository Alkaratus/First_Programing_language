#include "Zone_Object.h"
#include "../../Visitor/Visitor.h"

Zone_Object::Zone_Object(Position position, bool _left_closed, bool _right_closed, std::shared_ptr<Operative_Object> _left_end, std::shared_ptr<Operative_Object> _right_end):
	Set_Object(position),
	left_closed(_left_closed),
	right_closed(_right_closed),
	left_end(_left_end),
	right_end(_right_end)
{}

void Zone_Object::accept(Visitor &visitor) {
	visitor.visit(*this);
}

std::string Zone_Object::generate_code() {
	std::string code="zone ";
	if (left_closed) { 
		code +="[ ";
	}
	else {
		code +="( ";
	}
	code = code+ left_end->generate_code()+ right_end->generate_code();
	if (right_closed) {
		code += "] ";
	}
	else {
		code += ") ";
	}
	return code;
}

std::shared_ptr<Operative_Object>& Zone_Object::get_left_end() {
	return left_end;
}

std::shared_ptr<Operative_Object>& Zone_Object::get_right_end() {
	return right_end;
}

bool Zone_Object::is_left_closed() {
	return left_closed;
}

bool Zone_Object::is_right_closed() {
	return right_closed;
}