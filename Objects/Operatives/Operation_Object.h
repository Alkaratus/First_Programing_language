#pragma once
#include <memory>
#include "../Dependent/Operator_Object.h"
#include "Operative_Object.h"

class Operation_Object :public Operative_Object {
	std::shared_ptr<Operative_Object> operative_1, operative_2;
	Operator_Object _operator;
	std::string operator_to_string();
public:
	Operation_Object(Position position,std::shared_ptr<Operative_Object> _operative_1, Operator_Object _operator, std::shared_ptr<Operative_Object> _operative_2);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	std::shared_ptr<Operative_Object>& get_first_operative();
	std::shared_ptr<Operative_Object>& get_second_operative();
	Operator_Object get_operator();
};