#pragma once
#include <memory>
#include "Operatives/Operative_Object.h"
#include "Complilation_Object.h"

class Return_Object:public Compilation_Object{
	std::shared_ptr<Operative_Object> returned;
public:
	Return_Object(Position _position, std::shared_ptr<Operative_Object> returned);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	std::shared_ptr<Operative_Object> &get_returned();
};