#pragma once
#include <memory>
#include "Inspect_Is_Conditional_Object.h"
#include "../../Sets/Set_Object.h"

class In_Conditional_Object :public Inspect_Is_Conditional_Object {
	std::shared_ptr<Set_Object> set;
public:
	In_Conditional_Object(Position position, std::shared_ptr<Set_Object> set);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	std::shared_ptr<Set_Object> get_set();
};