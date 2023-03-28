#pragma once
#include <string>

class Executive {
public:
	virtual ~Executive() = default;
	virtual std::string read_word() = 0;
	virtual std::string read_line() = 0;
	virtual bool is_end() const = 0;
	virtual unsigned long long int get_position() = 0;
	virtual void set_position(unsigned long long int position) = 0;
};