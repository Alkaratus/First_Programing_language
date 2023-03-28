#pragma once
#include "../Overall/Position.h"
#include "../Overall/Compile_message.h"

class Source {
private:
	Position position;
	const short TAB_SIZE = 3;
protected:
	virtual char read_char() = 0;
public:
	Source(std::string file_name="main.apl");
	virtual ~Source()= default;
	char get_char();
	virtual bool is_end() const = 0;
	Position get_position() const;
	void set_position(Position _position);
};