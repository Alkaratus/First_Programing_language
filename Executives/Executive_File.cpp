#include "Executive_File.h"
#include <filesystem>

Executive_File::Executive_File(std::string filename, std::ios::ios_base::openmode mode):
	file(filename,mode){
	auto path= std::filesystem::current_path();
	if (!file.good()) {
		throw std::invalid_argument("Failed to open file");
	}
}

std::string Executive_File::read_line(){
	std::string line;
	getline(file,line);
	return line;
}

std::string Executive_File::read_word(){
	std::string word;
	file >> word;
	return word;
}

bool Executive_File::is_end() const{
	return file.eof();
}

void Executive_File::load(std::string text){
	file << text;
}

void Executive_File::set_position(unsigned long long int position){
	file.clear();
	file.seekg(position);
}

unsigned long long int Executive_File::get_position(){
	return file.tellg();
}
