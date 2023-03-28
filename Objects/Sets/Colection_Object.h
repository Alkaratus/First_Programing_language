#pragma once
#include <vector>
#include <memory>
#include "Set_Object.h"
#include "../Operatives/Operative_Object.h"

class Colection_Object :public Set_Object {
	std::vector<std::shared_ptr<Operative_Object>> colection;
public:
	Colection_Object(Position position,std::vector<std::shared_ptr<Operative_Object>> _colection);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	std::vector<std::shared_ptr<Operative_Object>> &get_colection();
};