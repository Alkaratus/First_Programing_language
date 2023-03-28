#include "As_converters.h"
#include <map>
#include <functional>
#include <stdexcept>

using std::any, std::string, std::optional;

namespace As_Converters {
	using std::pair;
	using namespace Data_Type;
	const std::map<pair<string, string>, std::function<any(any)>>string_dictionary{
		{{"(char","float"},char_to_float},
		{{"(char","int"},char_to_int},
		{{"(char","string"},char_to_string},
		{{"(float","char"},float_to_char},
		{{"(float","int"},float_to_int},
		{{"(float","string"},float_to_string},
		{{"(int","char"},int_to_char},
		{{"(int","float"},int_to_float},
		{{"(int","string"},int_to_string},
		{{"(string","char"},string_to_char},
		{{"(string","float"},string_to_float},
		{{"(string","int"},string_to_int},
	};
	const std::map<pair<type, type>, std::function<any(any)>>type_dictionary{
		{{_char,_float},char_to_float},
		{{_char,_int},char_to_int},
		{{_char,_string},char_to_string},
		{{_float,_char},float_to_char},
		{{_float,_int},float_to_int},
		{{_float,_string},float_to_string},
		{{_int,_char},int_to_char},
		{{_int,_float},int_to_float},
		{{_int,_string},int_to_string},
		{{_string,_char},string_to_char},
		{{_string,_float},string_to_float},
		{{_string,_int},string_to_int},
	};
}

any As_Converters::convert(any value, string current_type, string new_type){
	return string_dictionary.at({ current_type, new_type })(value);
}

any As_Converters::convert(any value, Data_Type::type current_type, Data_Type::type new_type){
	return type_dictionary.at({ current_type, new_type })(value);
}

any As_Converters::char_to_float(any value){
	return static_cast<double>(std::any_cast<char>(value));
}

any As_Converters::char_to_int(any value){
	return static_cast<long long int>(std::any_cast<char>(value));
}

any As_Converters::char_to_string(any value){
	std::string converted = " ";
	converted[0] = std::any_cast<char>(value);
	return converted;
}

any As_Converters::float_to_char(any value){
	return {};
}

any As_Converters::float_to_int(any value){
	auto concrate_value = std::any_cast<double>(value);
	auto int_value = round(concrate_value);
	if (int_value == concrate_value) {
		return static_cast<long long int>(int_value);
	}
	else {
		return {};
	}
}

any As_Converters::float_to_string(any value){
	return std::to_string(std::any_cast<double>(value));
}

any As_Converters::int_to_char(any value){
	return {};
}

any As_Converters::int_to_float(any value){
	return static_cast<double>(std::any_cast<long long int>(value));
}

any As_Converters::int_to_string(any value){
	return std::to_string(std::any_cast<long long int>(value));
}

any As_Converters::string_to_char(any value){
	auto concreate_value = std::any_cast<string>(value);
	if (concreate_value.size() == 1) {
		return concreate_value[0];
	}
	return {};
}

any As_Converters::string_to_float(any value){
	auto concreate_value = std::any_cast<string>(value);
	try {
		auto converted = stod(concreate_value);
		return converted;
	}
	catch (std::logic_error e) {
		return {};
	}
}

any As_Converters::string_to_int(any value){
	auto concreate_value = std::any_cast<string>(value);
	try {
		auto converted = stoll(concreate_value);
		return converted;
	}
	catch (std::logic_error e) {
		return {};
	}
}
