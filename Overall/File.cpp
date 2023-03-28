#include "File.h"

File::File(std::string path) {
	auto const last_slash_index = path.find_last_of('/');
	if (last_slash_index != -1) {
		directory = path.substr(0, last_slash_index);
		file_name = path.substr(last_slash_index + 1);
	}
	else {
		directory = "";
		file_name = path;
	}
}

std::string File::get_directory() const{
	return directory;
}

std::string File::get_file_name() const{
	return file_name;
}
