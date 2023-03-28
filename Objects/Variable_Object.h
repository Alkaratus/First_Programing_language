#pragma once
#include <memory>
#include "Complilation_Object.h"
#include "Dependent/Variable_Essence.h"
#include "Operatives/Operative_Object.h"

class Variable_Object :public Compilation_Object {
	Variable_Essence essence;
	std::shared_ptr<Operative_Object> value;
public:
	Variable_Object(Position position, Variable_Essence _essence, std::shared_ptr<Operative_Object> _value);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	void set_essence(Variable_Essence essence);
	Variable_Essence &get_essence();
	std::shared_ptr<Operative_Object> get_value();
};