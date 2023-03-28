#pragma once
#include "Inspect_Is_Conditional_Object.h"
#include "../../../Token/Token.h"

class Default_Conditional_Object :public Inspect_Is_Conditional_Object {
public:
	Default_Conditional_Object(Position position);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
};