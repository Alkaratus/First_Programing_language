#pragma once
#include<memory>
#include "Scoped_Object.h"
#include "../Inspect_Conditionals/Inspect_Conditional_Object.h"

class Inspect_Option_Object :public Scoped_Object {
	std::shared_ptr<Inspect_Conditional_Object> condition;
public:
	Inspect_Option_Object(Position position, std::shared_ptr<Inspect_Conditional_Object> condition);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	std::shared_ptr<Inspect_Conditional_Object> get_condition();
};