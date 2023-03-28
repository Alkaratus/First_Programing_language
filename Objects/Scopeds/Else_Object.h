#pragma once
#include "Scoped_Object.h"
#include "../Operatives/Operative_Object.h"
class Else_Object :public Scoped_Object {
public:
	Else_Object(Position position);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
};