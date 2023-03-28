#pragma once
#include <memory>
#include "Set_Object.h"
#include "../Operatives/Operative_Object.h"

class Zone_Object :public Set_Object {
	bool left_closed, right_closed;
	std::shared_ptr<Operative_Object> left_end, right_end;
public:
	Zone_Object(Position position, bool left_closed, bool right_closed, std::shared_ptr<Operative_Object> left_end, std::shared_ptr<Operative_Object> right_end);
	void accept(Visitor &visitor) override;
	std::string generate_code() override;
	std::shared_ptr<Operative_Object> &get_left_end();
	std::shared_ptr<Operative_Object> &get_right_end();
	bool is_left_closed();
	bool is_right_closed();
};