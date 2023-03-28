#pragma once
#include <memory>
#include <vector>
#include "Complilation_Object.h"
#include "Operatives/Operative_Object.h"
#include "Scopeds/Inspect_Option_Object.h"

class Inspect_Object :public Compilation_Object {
	std::shared_ptr<Operative_Object> inspected;
	std::vector<std::shared_ptr<Inspect_Option_Object>> options;
public:
	Inspect_Object(Position position, std::shared_ptr<Operative_Object> inspected,std::vector<std::shared_ptr<Inspect_Option_Object>> options);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	std::shared_ptr<Operative_Object> get_inspected();
	std::vector<std::shared_ptr<Inspect_Option_Object>> &get_options();
};