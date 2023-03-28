#pragma once
#include "../Overall/Position.h"

class Visitor;

class Compilation_Object {
	Position position;
public:
	Compilation_Object(Position _position);
	~Compilation_Object() = default;
	virtual void accept(Visitor &visitor)=0;
	virtual std::string generate_code()=0;
	Position get_position();
};