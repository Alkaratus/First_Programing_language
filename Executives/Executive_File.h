#pragma once
#include <fstream>
#include "Executive.h"

class Executive_File :public Executive {
	std::fstream file;
public:
	Executive_File(std::string filename, std::ios::ios_base::openmode mode);

	std::string read_line() override;
	std::string read_word() override;
	bool is_end() const override;
	void set_position(unsigned long long int position) override;
	unsigned long long int get_position() override;

	void load(std::string text);
};