#pragma once
#include <any>
#include <map>
#include <memory>
#include <string>
#include <variant>
#include <functional>

typedef std::variant<std::shared_ptr<char>, std::shared_ptr<double>, std::shared_ptr<long long int>, std::shared_ptr<std::string>> returned_value;

namespace Library {
	using std::string, std::shared_ptr, std::map, std::any;
	std::function< returned_value(std::vector<shared_ptr<void>>)> get_function(string name);
	returned_value out(std::vector<shared_ptr<void>> arguments);
	returned_value out1(std::vector<shared_ptr<void>> arguments);
	returned_value out2(std::vector<shared_ptr<void>> arguments);
	returned_value out3(std::vector<shared_ptr<void>> arguments);
	returned_value inp(std::vector<shared_ptr<void>> arguments);
	returned_value inp1(std::vector<shared_ptr<void>> arguments);
	returned_value inp2(std::vector<shared_ptr<void>> arguments);
	returned_value inp3(std::vector<shared_ptr<void>> arguments);
	returned_value _sqrt(std::vector<shared_ptr<void>> arguments);
}


template <typename T>T get_value_from_void_ptr(std::shared_ptr<void> void_ptr) {
	auto ptr = void_ptr.get();
	return *(T*)ptr;
}
