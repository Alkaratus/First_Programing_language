#include <iostream>
#include "../Final_Functions/Final_Functions.h"
#include <filesystem>

using std::cout,std::cin,std::string;

int main(int argc, char*argv[]) {
	std::filesystem::path cwd = std::filesystem::current_path();
	cout << "current interpreter_file: " << cwd<<'\n';
	
	std::string filename;
	if (argc > 1) {
		filename = argv[1];
	}
	else {
		cout << "Give filename you want to execute\n";
		cin >> filename;
	}
	try {
		Source_File source(filename);
		execute(source);
		cout << "\nDone\n";
	}
	catch(const std::exception& exeption){
		cout << exeption.what();
	}
	return 0;
}
