#pragma once
#include "Scoped_Object.h"
#include "../Operatives/Operative_Object.h"
class If_Object :public Scoped_Object {
	std::shared_ptr<Operative_Object> condition;
public:
	If_Object(Position position, std::shared_ptr<Operative_Object> condition);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	std::shared_ptr<Operative_Object> &get_condition();
};