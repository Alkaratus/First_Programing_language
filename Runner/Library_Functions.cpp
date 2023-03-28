#include "Library_Functions.h"
#include <iostream>
#include <cmath>

using std::string, std::shared_ptr, std::map, std::any;

namespace Library {
	const std::map <string, std::function<returned_value(std::vector<shared_ptr<void>>)>> dictionary{
		{"@out",out},
		{"@out1",out1},
		{"@out2",out2},
		{"@out3",out3},
		{"@inp",inp},
		{"@inp1",inp1},
		{"@inp2",inp2},
		{"@inp3",inp3},
		{"@sqrt",_sqrt}
	};
}

shared_ptr<char> const FOR_VOID = 0;

std::function<returned_value(std::vector<shared_ptr<void>> arguments)> Library::get_function(string name){
	return dictionary.at(name);
}

returned_value Library::out(std::vector<shared_ptr<void>> arguments){
	std::cout << get_value_from_void_ptr<string>(arguments[0]);
	return FOR_VOID;
}

returned_value Library::out1(std::vector<shared_ptr<void>> arguments){
	std::cout << get_value_from_void_ptr<long long int>(arguments[0]);
	return FOR_VOID;
}

returned_value Library::out2(std::vector<shared_ptr<void>> arguments){
	std::cout << get_value_from_void_ptr<char>(arguments[0]);
	return FOR_VOID;
}

returned_value Library::out3(std::vector<shared_ptr<void>> arguments){
	std::cout << get_value_from_void_ptr<double>(arguments[0]);
	return FOR_VOID;
}

returned_value Library::inp(std::vector<shared_ptr<void>> arguments) {
	string value;
	std::cin >>value;
	auto ptr = std::static_pointer_cast<string>(arguments[0]);
	*ptr.get() = value;
	return FOR_VOID;
}

returned_value Library::inp1(std::vector<shared_ptr<void>> arguments) {
	long long int value;
	std::cin >> value;
	auto ptr = std::static_pointer_cast<long long int>(arguments[0]);
	*ptr.get() = value;
	return FOR_VOID;
}

returned_value Library::inp2(std::vector<shared_ptr<void>> arguments) {
	char value;
	std::cin >> value;
	auto ptr = std::static_pointer_cast<char>(arguments[0]);
	*ptr.get() = value;
	return FOR_VOID;
}

returned_value Library::inp3(std::vector<shared_ptr<void>> arguments) {
	double value;
	std::cin >> value;
	auto ptr=std::static_pointer_cast<double>(arguments[0]);
	*ptr.get() = value;
	return FOR_VOID;
}

returned_value Library::_sqrt(std::vector<shared_ptr<void>> arguments){
	auto result = get_value_from_void_ptr<long long int>(arguments[0]);
	return std::make_shared<long long int>(static_cast<long long int>(sqrt(result)));
}


