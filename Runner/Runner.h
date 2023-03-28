#pragma once
#include <vector>
#include <string>
#include <map>
#include <any>
#include <memory>
#include <optional>
#include "../Executives/Executive.h"
#include "Splited_Line.h"
#include "Operations.h"
#include "Library_Functions.h"

using std::string, std::shared_ptr, std::pair, std::any, std::make_shared;

class Runner {
	Executive &executive;

	std::map<string, shared_ptr<void>> vars;
	std::map<string, unsigned long long int>function_jumps;
	std::map<string, string>function_types;
	string line;

	any _register;
	void get_next_line();

public:
	void prepare_to_run();

	bool create_variable(Splitted_Line words, bool initialized);

	template <typename T>std::optional<pair<string, shared_ptr<T>>> execute_declaration(Splitted_Line words, string type, bool initialized, shared_ptr<T>(Runner::* value_creator)(Splitted_Line&));

	shared_ptr<char> create_char_value(Splitted_Line& words);
	shared_ptr<double> create_float_value(Splitted_Line& words);
	shared_ptr<long long int> create_int_value(Splitted_Line& words);
	shared_ptr<string> create_string_value(Splitted_Line& words);

	template <typename T>shared_ptr<T> execute_call(Splitted_Line& words);
	template <typename T>shared_ptr<T>execute_call_v(Splitted_Line& words);
	template<typename T>std::shared_ptr<T>execute_f_call(Splitted_Line& words);
	bool execute_void_f_call(Splitted_Line words);
	void execute_function_body(std::string function_name, std::vector<string> arguments_names);

	std::vector<string> create_arguments(Splitted_Line& words);
	void clear_arguments(std::vector<string> names);
	pair<string, shared_ptr<void>> create_argument(Splitted_Line type, Splitted_Line& words);
	bool is_mark(Splitted_Line& words, string mark);

	template <typename T> shared_ptr<T> create_argument_value(Splitted_Line& words, shared_ptr<T>(Runner::* value_creator)(Splitted_Line&));

	void execute_scope(string exit_line);
	void skip_scope(string entry_word, string exit_line);

	void execute_lib_function(std::string function_name, std::vector<string> arguments_names);

	bool execute_return(Splitted_Line words);
	any return_value(string type);
	any return_default(string type);
	
	template <typename T> shared_ptr<T>execute_operation(Splitted_Line& words, string type, shared_ptr<T>(Runner::* value_creator)(Splitted_Line&), shared_ptr<T>(operations)(shared_ptr<T>, shared_ptr<T>, string));

	shared_ptr<char> execute_char_ret_operation(Splitted_Line &words);

	shared_ptr<char> execute_char_floats_operation(Splitted_Line &words);
	shared_ptr<char> execute_char_ints_operation(Splitted_Line &words);
	shared_ptr<char> execute_char_strings_operation(Splitted_Line &words);

	bool execute_assignment(Splitted_Line& words);
	template <typename T>bool execute_assignment(Splitted_Line words, string type, shared_ptr<T>(Runner::*value_creator)(Splitted_Line&));
	
	template <typename T>T create_const(Splitted_Line& words, T(converter)(string&) );
	
	shared_ptr<char> execute_In_Set(Splitted_Line& words);
	
	shared_ptr<char> execute_char_In_Set(Splitted_Line& words);
	shared_ptr<char> execute_float_In_Set(Splitted_Line& words);
	shared_ptr<char> execute_int_In_Set(Splitted_Line& words);
	shared_ptr<char> execute_string_In_Set(Splitted_Line& words);

	template <typename T>shared_ptr<char>compare_with_colection(shared_ptr<T> value, Splitted_Line& words, shared_ptr<T>(Runner::* value_creator)(Splitted_Line&));
	template <typename T>shared_ptr<char>compare_with_zone(shared_ptr<T> value, Splitted_Line& words, shared_ptr<T>(Runner::* value_creator)(Splitted_Line&));
	bool is_closed_zone(Splitted_Line& words);

	bool execute_inspect(Splitted_Line& words);
	any create_inspected_value(Splitted_Line& words);
	bool execute_option(Splitted_Line& words, any value, string type);
	bool check_option_condition(Splitted_Line& words, any value, string type);
	std::optional<bool> check_is_condition(Splitted_Line& words, any value, string type);
	std::optional<bool> check_in_condition(Splitted_Line& words, any value, string type);
	shared_ptr<char> check_in_colection_condition(Splitted_Line& words, any value, string type);
	shared_ptr<char> check_in_zone_condition(Splitted_Line& words, any value, string type);
	shared_ptr<char> check_compare_condition(Splitted_Line& words, any value, string type);
	bool check_as_condition(Splitted_Line& words, any value, string type);

	bool execute_conditional(Splitted_Line &words);
	bool execute_if(Splitted_Line& words);
	bool execute_else(Splitted_Line& words);

	bool execute_while(Splitted_Line& words);
	bool check_condition(Splitted_Line& words);

	Runner(Executive &executive);
	void create_function_jump(Splitted_Line words);
	int run();
};


namespace Run_Functions {
	char create_const_char(string& word);
	double create_const_float(string& word);
	long long int create_const_int(string& word);
	std::string create_const_string(string& word);
	template <typename T> shared_ptr<T> create_copy(shared_ptr<T>original);
	template <typename T>shared_ptr<char> compare_in_zone(shared_ptr<T>value_1, shared_ptr<T>value_2, bool closed);
}

template <typename T>
inline std::optional<pair<string, shared_ptr<T>>> Runner::execute_declaration(Splitted_Line words, string type, bool initialized, shared_ptr<T>(Runner::* value_creator)(Splitted_Line&)) {
	if (words.get_word(1) != type) {
		return {};
	}
	shared_ptr<T> value = nullptr;
	if (initialized) {
		words.increment_index(4);
		value = (this->*value_creator)(words);
	}
	return std::make_pair(words.get_word(3), value);
}

template<typename T>
inline shared_ptr<T> Runner::execute_operation(Splitted_Line& words, string type, shared_ptr<T>(Runner::* value_creator)(Splitted_Line&), shared_ptr<T>(operations)(shared_ptr<T>, shared_ptr<T>,string)){
	if (words.get_word() != type) {
		return nullptr;
	}
	words.increment_index();
	auto first_value = (this->*value_creator)(words);
	auto _operator = words.get_word_and_increment_index();
	auto second_value = (this->*value_creator)(words);
	words.increment_index();
	return operations(first_value, second_value, _operator);
}

template <typename T>
inline shared_ptr<T> Runner::execute_call(Splitted_Line& words) {
	if (auto pointer = execute_call_v<T>(words)) {
		return pointer;
	}
	if (auto pointer = execute_f_call<T>(words)) {
		return pointer;
	}
	return nullptr;
}

template<typename T>
inline shared_ptr<T> Runner::execute_call_v(Splitted_Line& words){
	if (words.get_word() != "call_v") {
		return nullptr;
	}
	words.increment_index();
	auto ptr = vars[words.get_word_and_increment_index()];
	auto value = get_value_from_void_ptr<T>(ptr);
	auto new_ptr = std::static_pointer_cast<T,void>(ptr);
	*new_ptr.get() = value;
	return new_ptr;
}

template<typename T>
inline std::shared_ptr<T> Runner::execute_f_call(Splitted_Line &words){
	if (words.get_word() != "call_f") {
		return nullptr;
	}
	words.increment_index();
	auto buffer = executive.get_position();
	auto function_name = words.get_word_and_increment_index();
	executive.set_position(function_jumps[function_name]);
	words.increment_index();
	auto args = create_arguments(words);
	execute_function_body(function_name,args);
	words.increment_index();
	clear_arguments(args);
	executive.set_position(buffer);
	auto returned =return_value(function_types[function_name]);
	auto converted = make_shared<T>(std::any_cast<T>(returned));
	_register = {};
	return converted;
}

template<typename T>
inline shared_ptr<T> Runner::create_argument_value(Splitted_Line& words, shared_ptr<T>(Runner::* value_creator)(Splitted_Line&)){
	auto copy = is_mark(words, "#");
	auto ref = (this->*value_creator)(words);
	if (copy) {
		return Run_Functions::create_copy<T>(ref);
	}
	return ref;
}

template <typename T>
inline bool Runner::execute_assignment(Splitted_Line words, string type, shared_ptr<T>(Runner::*value_creator)(Splitted_Line&)) {
	if (words.get_word(0) != type) {
		return false;
	}
	words.increment_index();
	auto first_value = execute_call_v<T>(words);
	auto _operator = words.get_word_and_increment_index();
	auto second_value = (this->*value_creator)(words);
	Operations::assign<T>(first_value, second_value);
	words.increment_index();
	return true;
}

template<typename T>
inline T Runner::create_const(Splitted_Line& words, T(converter)(string&)) {
	return converter(words.get_word_and_increment_index());
}

template <typename T>
inline shared_ptr<char>Runner::compare_with_colection(shared_ptr<T> value, Splitted_Line& words, shared_ptr<T>(Runner::* value_creator)(Splitted_Line&)) {
	if (words.get_word() != "colection") {
		return nullptr;
	}
	words.increment_index();
	words.increment_index();
	while (words.get_word() != "}") {
		auto compared = (this->*value_creator)(words);
		if (*Operations::equal(compared, value).get() == 1) {
			return make_shared<char>('\1');
		}
	}
	return make_shared<char>('\0');
}

template <typename T>
inline shared_ptr<char>Runner::compare_with_zone(shared_ptr<T> value, Splitted_Line& words, shared_ptr<T>(Runner::* value_creator)(Splitted_Line&)) {
	if (words.get_word() != "zone") {
		return nullptr;
	}
	words.increment_index();
	auto closed = is_closed_zone(words);
	auto first_compared = (this->*value_creator)(words);
	if (!(*Run_Functions::compare_in_zone(first_compared, value, closed).get())) {
		return make_shared<char>('\0');
	}
	auto second_compared = (this->*value_creator)(words);
	closed = is_closed_zone(words);
	if (!(*Run_Functions::compare_in_zone(value, second_compared, closed).get())) {
		return make_shared<char>('\0');
	}
	return make_shared<char>('\1');
}

template<typename T>
inline shared_ptr<char> Run_Functions::compare_in_zone(shared_ptr<T> value_1, shared_ptr<T> value_2, bool closed){
	if (closed) {
		return Operations::less_or_equal(value_1, value_2);
	}
	return Operations::less_than(value_1, value_2);
}

template<typename T>
inline shared_ptr<T> Run_Functions::create_copy(shared_ptr<T> original) {
	return make_shared<T>(*original.get());
}