#pragma once
#include <memory>
#include "Inspect_Is_Conditional_Object.h"
#include "../../Dependent/Operator_Object.h"
#include "../../Operatives/Constanses/Constans_Object.h"

class Compare_Conditional_Object :public Inspect_Is_Conditional_Object {
	Operator_Object operation;
	std::shared_ptr<Constans_Object> compared;
public:
	Compare_Conditional_Object(Position position, std::shared_ptr<Constans_Object> compared, Operator_Object operation=Operator_Object(Token::equal));
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	Operator_Object get_operator() const;
	std::shared_ptr<Constans_Object> get_compared();
};