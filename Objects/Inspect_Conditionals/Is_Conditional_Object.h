#pragma once
#include <memory>
#include "Inspect_Conditional_Object.h"
#include "Inspect_Is_Conditionals/Inspect_Is_Conditional_Object.h"

class Is_Conditional_Object :public Inspect_Conditional_Object {
	std::shared_ptr<Inspect_Is_Conditional_Object> condition;
public:
	Is_Conditional_Object(Position position, std::shared_ptr<Inspect_Is_Conditional_Object> condition);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	std::shared_ptr<Inspect_Is_Conditional_Object> get_condition();
};