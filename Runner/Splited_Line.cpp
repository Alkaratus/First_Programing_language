#include "Splited_Line.h"



Splitted_Line::Splitted_Line(std::string line):
	words(split_string(line)),
	index(0)
{}

std::string Splitted_Line::get_word(ullint _index){
	return words[_index];
}

std::string Splitted_Line::get_word(){
	return words[index];
}

std::string& Splitted_Line::get_word_and_increment_index(){
	return words[index++];
}

Splitted_Line::ullint Splitted_Line::get_size(){
	return words.size();
}

void Splitted_Line::increment_index(ullint steps){
	index+=steps;
}

std::vector<std::string> split_string(std::string line) {
	std::vector<std::string> words;
	unsigned long long int index = 0;
	while (index < line.length()) {
		auto next_word = separate_word(line, index,' ');
		if (next_word[0] == '"') {
			next_word = separate_word(line, index + 1, '"');
		}
		index = index + next_word.length() + 1;
		words.push_back(next_word);
	}

	return words;
}

std::string separate_word(std::string line, unsigned long long int index, char separator) {
	auto next_space = line.find_first_of(separator, index);
	if (next_space != -1) {
		return line.substr(index, next_space - index);
	}
	else {
		return line.substr(index);
	}
}