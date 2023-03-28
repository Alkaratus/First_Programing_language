#pragma once
#include <memory>
#include "Operative_Object.h"
#include "../Sets/Set_Object.h"

class In_Set_Object :public Operative_Object {
	std::shared_ptr<Operative_Object> checked;
	std::shared_ptr<Set_Object> set;
public:
	In_Set_Object(Position position, std::shared_ptr<Operative_Object> checked, std::shared_ptr<Set_Object> set);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	std::shared_ptr<Operative_Object> get_checked();
	std::shared_ptr<Set_Object> get_set();
};