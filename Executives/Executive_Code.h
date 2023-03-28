#pragma once
#include "Executive.h"

class Executive_Code :public Executive {
	std::string text;
	unsigned long long int index;
public:
	Executive_Code(std::string _text);
	
	std::string read_line() override;
	std::string read_word() override;
	void set_position(unsigned long long int position) override;
	unsigned long long int get_position() override;
	bool is_end() const override;

	std::string get_text(unsigned long long int last_index);
};