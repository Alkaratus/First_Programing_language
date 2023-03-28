#pragma once
#include <string>

class File {
	std::string directory, file_name;
public:
	File(std::string path= "main.apl");
	std::string get_directory() const;
	std::string get_file_name() const;
};