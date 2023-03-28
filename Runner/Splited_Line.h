#pragma once
#include <vector>
#include <string>



class Splitted_Line{
	typedef unsigned long long int ullint;

	std::vector<std::string> words;
	ullint index;
public:
	Splitted_Line(std::string line);
	std::string get_word(ullint index);
	std::string get_word();
	std::string &get_word_and_increment_index();
	ullint get_size();
	void increment_index(ullint steps=1);
};

std::vector<std::string> split_string(std::string line);
std::string separate_word(std::string line, unsigned long long int index, char separator);