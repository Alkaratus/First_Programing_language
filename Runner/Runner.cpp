#include "Runner.h"
#include "As_converters.h"

Runner::Runner(Executive &_executive):
	executive(_executive),
	_register({}){
	prepare_to_run();
}

void Runner::get_next_line(){
	line = executive.read_line();
	while (line == "" && !executive.is_end()) {
		line = executive.read_line();
	}
}

void Runner::prepare_to_run(){
	get_next_line();
	while (!executive.is_end()) {
		auto words = Splitted_Line(line);
		create_function_jump(words);
		create_variable(words,true);
		get_next_line();
	}
}

void Runner::create_function_jump(Splitted_Line words) {
	if (words.get_word(0) != "FUNCTION") {
		return;
	}
	function_jumps.emplace(words.get_word(2), executive.get_position());
	function_types.emplace(words.get_word(2), words.get_word(1));
	skip_scope("FUNCTION", "FUNCTION_END");
}

bool Runner::create_variable(Splitted_Line words,bool initialized){
	if (words.get_word(0) != "declare") {
		return false;
	}
	if (auto new_char = execute_declaration<char>(words, "char", initialized, &Runner::create_char_value)) {
		vars.emplace(new_char.value());
		return true;
	}
	if (auto new_float = execute_declaration<double>(words, "float", initialized, &Runner::create_float_value)) {
		vars.emplace(new_float.value());
		return true;
	}
	if (auto new_int = execute_declaration<long long int>(words, "int", initialized, &Runner::create_int_value)) {
		vars.emplace(new_int.value());
		return true;
	}
	auto new_string= execute_declaration<string>(words, "string", initialized, &Runner::create_string_value);
	vars.emplace(new_string.value());
}

shared_ptr<char> Runner::create_char_value(Splitted_Line& words) {
	if (auto value = execute_char_ret_operation(words)) {
		return value;
	}
	if (auto value = execute_call<char>(words)) {
		return value;
	}
	return make_shared<char>(create_const<char>(words, Run_Functions::create_const_char));
}

shared_ptr<double> Runner::create_float_value(Splitted_Line& words) {
	if (auto value = execute_operation<double>(words, "(float", &Runner::create_float_value, Operations::floats_operations)) {
		return value;
	}
	if (auto value = execute_call<double>(words)) {
		return value;
	}
	return make_shared<double>(create_const<double>(words, Run_Functions::create_const_float));
}

shared_ptr<long long int> Runner::create_int_value(Splitted_Line& words) {
	if (auto value= execute_operation<long long int>(words, "(int", &Runner::create_int_value, Operations::ints_operations)) {
		return value;
	}
	if (auto value = execute_call<long long int>(words)) {
		return value;
	}
	return make_shared<long long int>(create_const<long long int>(words, Run_Functions::create_const_int));
}

shared_ptr<string> Runner::create_string_value(Splitted_Line& words) {
	if (auto value = execute_operation<string>(words, "(string", &Runner::create_string_value, Operations::strings_operations)) {
		return value;
	}
	if (auto value = execute_call<string>(words)) {
		return value;
	}
	return make_shared<string>(create_const<string>(words, Run_Functions::create_const_string));
}

shared_ptr<char> Runner::execute_char_ret_operation(Splitted_Line &words) {
	if (auto value = execute_operation<char>(words, "(char", &Runner::create_char_value, Operations::chars_operations)) {
		return value;
	}
	if (auto value = execute_char_floats_operation(words)) {
		return value;
	}
	if (auto value = execute_char_ints_operation(words)) {
		return value;
	}
	if (auto value = execute_char_strings_operation(words)) {
		return value;
	}
	if (auto value = execute_In_Set(words)) {
		return value;
	}
	return nullptr;
}

shared_ptr<char> Runner::execute_char_floats_operation(Splitted_Line &words) {
	if (words.get_word() != "(float") {
		return nullptr;
	}
	words.increment_index();
	auto first_value = create_float_value(words);
	auto _operator = words.get_word_and_increment_index();
	auto second_value = create_float_value(words);
	words.increment_index();
	return Operations::compare<double>(first_value, second_value, _operator);
}

shared_ptr<char> Runner::execute_char_ints_operation(Splitted_Line &words) {
	if (words.get_word() != "(int") {
		return nullptr;
	}
	words.increment_index();
	auto first_value = create_int_value(words);
	auto _operator = words.get_word_and_increment_index();
	auto second_value = create_int_value(words);
	words.increment_index();
	return Operations::compare<long long int>(first_value, second_value, _operator);
}

shared_ptr<char> Runner::execute_char_strings_operation(Splitted_Line &words) {
	if (words.get_word() != "(string") {
		return nullptr;
	}
	words.increment_index();
	auto first_value = create_string_value(words);
	auto _operator = words.get_word_and_increment_index();
	auto second_value = create_string_value(words);
	words.increment_index();
	return Operations::compare<string>(first_value, second_value, _operator);
}

shared_ptr<char> Runner::execute_In_Set(Splitted_Line& words){
	if (words.get_word() != "In_Set") {
		return nullptr;
	}
	words.increment_index();
	if (auto result = execute_char_In_Set(words)) {
		return result;
	}
	if (auto result = execute_float_In_Set(words)) {
		return result;
	}
	if (auto result = execute_int_In_Set(words)) {
		return result;
	}
	if (auto result = execute_string_In_Set(words)) {
		return result;
	}
	return shared_ptr<char>();
}

shared_ptr<char> Runner::execute_char_In_Set(Splitted_Line& words) {
	if (words.get_word() != "(char") {
		return nullptr;
	}
	words.increment_index();
	auto compared = create_char_value(words);
	if (auto result = compare_with_colection<char>(compared, words,&Runner::create_char_value)) {
		return result;
	}
	if (auto result = compare_with_zone<char>(compared, words, &Runner::create_char_value)) {
		return result;
	}
	return nullptr;
}

shared_ptr<char> Runner::execute_float_In_Set(Splitted_Line& words) {
	if (words.get_word() != "(float") {
		return nullptr;
	}
	words.increment_index();
	auto compared = create_float_value(words);
	if (auto result = compare_with_colection<double>(compared, words, &Runner::create_float_value)) {
		return result;
	}
	if (auto result = compare_with_zone<double>(compared, words, &Runner::create_float_value)) {
		return result;
	}
	return nullptr;
}

shared_ptr<char> Runner::execute_int_In_Set(Splitted_Line& words) {
	if (words.get_word() != "(int") {
		return nullptr;
	}
	words.increment_index();
	auto compared = create_int_value(words);
	if (auto result = compare_with_colection<long long int>(compared, words, &Runner::create_int_value)) {
		return result;
	}
	if (auto result = compare_with_zone<long long int>(compared, words, &Runner::create_int_value)) {
		return result;
	}
	return nullptr;
}

shared_ptr<char> Runner::execute_string_In_Set(Splitted_Line& words){
	if (words.get_word() != "(string") {
		return nullptr;
	}
	words.increment_index();
	auto compared = create_string_value(words);
	if (auto result = compare_with_colection<string>(compared, words, &Runner::create_string_value)) {
		return result;
	}
	if (auto result = compare_with_zone<string>(compared, words, &Runner::create_string_value)) {
		return result;
	}
	return nullptr;
}

bool Runner::is_closed_zone(Splitted_Line& words) {
	auto closed = is_mark(words, "[") || is_mark(words, "]");
	if (!closed) {
		words.increment_index();
	}
	return closed;
}

std::vector<string> Runner::create_arguments(Splitted_Line &words) {
	get_next_line();
	get_next_line();
	unsigned short argc=0;
	std::vector<string>arguments_names;
	while (line != "ARGUMENTS_END") {
		Splitted_Line line_words(line);
		auto argument=create_argument(line_words, words);
		arguments_names.push_back(argument.first);
		vars.emplace(argument);
		get_next_line();
		argc++;
	}
	return arguments_names;
}

void Runner::clear_arguments(std::vector<string>names) {
	for (auto &name:names) {
		vars.erase(name);
	}
}

pair<string, shared_ptr<void>> Runner::create_argument(Splitted_Line type, Splitted_Line &words){
	auto new_char = execute_declaration<char>(type, "char", false, &Runner::create_char_value);
	if (new_char.has_value()) {
		auto value = new_char.value();
		value.second = create_argument_value<char>(words, &Runner::create_char_value);
		return value;
	}
	auto new_float = execute_declaration<double>(type, "float", false, &Runner::create_float_value);
	if (new_float.has_value()) {
		auto value = new_float.value();
		value.second = create_argument_value<double>(words, &Runner::create_float_value);
		return value;
	}
	auto new_int = execute_declaration<long long int>(type, "int", false, &Runner::create_int_value);
	if (new_int.has_value()) {
		auto value = new_int.value();
		value.second = create_argument_value<long long int>(words, &Runner::create_int_value);
		return value;
	}
	auto new_string = execute_declaration<string>(type, "string", false, &Runner::create_string_value);
	auto value = new_string.value();
	value.second = create_argument_value<string>(words, &Runner::create_string_value);
	return value;
}

bool Runner::is_mark(Splitted_Line& words, string mark) {
	if (words.get_word() == mark) {
		words.increment_index();
		return true;
	}
	return false;
}

bool Runner::execute_void_f_call(Splitted_Line words) {
	if (words.get_word()!= "call_f") {
		return false;
	}
	words.increment_index();
	auto buffer = executive.get_position();
	auto function_name = words.get_word_and_increment_index();
	executive.set_position(function_jumps[function_name]);
	words.increment_index();
	auto args=create_arguments(words);
	execute_function_body(function_name,args);
	words.increment_index();
	clear_arguments(args);
	executive.set_position(buffer);
	return true;
}

void Runner::execute_function_body(std::string function_name, std::vector<string> arguments_names) {
	if (function_name[0] == '@') {
		execute_lib_function(function_name, arguments_names);
	}
	else {
		execute_scope("FUNCTION_END");
		return_value(function_types[function_name]);
	}
}

bool Runner::execute_assignment(Splitted_Line& words) {
	if (execute_assignment<char>(words, "(char",&Runner::create_char_value)) {
		return true;
	}
	if (execute_assignment<double>(words, "(float", &Runner::create_float_value)) {
		return true;
	}
	if (execute_assignment<long long int>(words, "(int", &Runner::create_int_value)) {
		return true;
	}
	if (execute_assignment<string>(words, "(string", &Runner::create_string_value)) {
		return true;
	}
	return false;
}

void Runner::execute_scope(string exit_line){
	Splitted_Line words("");
	bool line_executed = false;
	 do{
		get_next_line();
		words = Splitted_Line(line);
		line_executed = create_variable(words, true);
		if (!line_executed) {
			line_executed = execute_inspect(words);
		}
		if (!line_executed) {
			line_executed = execute_void_f_call(words);
		}
		if (!line_executed) {
			line_executed = execute_assignment(words);
		}
		if (!line_executed) {
			line_executed = execute_conditional(words);
		}
		if (!line_executed) {
			line_executed = execute_while(words);
		}
		if (!line_executed) {
			//execute_return(words);
		}
	 } while ((!_register.has_value()) && line != exit_line);
}

void Runner::skip_scope(string entry_word, string exit_line) {
	unsigned int recursion = 1;
	do {
		get_next_line();
		auto words = Splitted_Line(line);
		if (line == exit_line) {
			recursion--;
		}
		else if (words.get_word(0) == entry_word) {
			recursion++;
		}
	} while (recursion);
}

void Runner::execute_lib_function(std::string function_name, std::vector<string> arguments_names){
	std::vector<shared_ptr<void>> arguments;
	for (auto name : arguments_names) {
		arguments.push_back(vars[name]);
	}
	_register=Library::get_function(function_name)(arguments);
}

any Runner::return_value(string type){
	if (_register.has_value()) {
		return _register;
	}
	return return_default(type);
}

bool Runner::execute_return(Splitted_Line words){
	if (words.get_word(0) != "return") {
		return false;
	}
	words.increment_index();
	auto type = words.get_word_and_increment_index();
	if (type == "char") {
		_register = *create_char_value(words).get();
	}
	if (type == "float") {
		_register = *create_float_value(words).get();
	}
	if (type == "int") {
		_register = *create_int_value(words).get();
	}
	if (type == "string") {
		_register = *create_string_value(words).get();
	}
	return true;
}

any Runner::return_default(string type){
	if (type == "char") {
		return '\0';
	}
	if (type == "float") {
		double value=0.0;
		return 0;
	}
	if (type == "int") {
		long long int value= 0;
		return value;
	}
	if (type == "string") {
		return "";
	}
	return {};
}

bool Runner::execute_inspect(Splitted_Line& words) {
	if (words.get_word(0) != "INSPECT") {
		return false;
	}
	words.increment_index();
	string type = words.get_word();
	any inspected = create_inspected_value(words);
	bool executed = false;
	do {
		get_next_line();
		auto next_words = Splitted_Line(line);
		executed= execute_option(next_words, inspected, type);
	} while (!executed && line != "INSPECT_END");
	if (executed) {
		skip_scope("INSPECT", "INSPECT_END");
	}
	return true;
}

any Runner::create_inspected_value(Splitted_Line& words) {
	any inspected;
	if (words.get_word() == "(char") {
		words.increment_index();
		auto value = create_char_value(words);
		inspected = (*value.get());
	}
	if (words.get_word() == "(float") {
		words.increment_index();
		auto value = create_float_value(words);
		inspected = (*value.get());
	}
	if (words.get_word() == "(int") {
		words.increment_index();
		auto value = create_int_value(words);
		inspected = (*value.get());
	}
	if (words.get_word() == "(string") {
		words.increment_index();
		auto value = create_string_value(words);
		inspected = (*value.get());
	}
	words.increment_index();
	return inspected;
}

bool Runner::execute_option(Splitted_Line& words, any value, string type) {
	if (words.get_word(0) != "OPTION") {
		return false;
	}
	words.increment_index();
	if (check_option_condition(words, value, type)) {
		auto added_const= words.get_word(1);
		execute_scope("OPTION_END");
		if (added_const != "is") {
			vars.erase(added_const);
		}
		return true;
	}
	skip_scope("OPTION", "OPTION_END");
	return false;
}

bool Runner::check_option_condition(Splitted_Line& words, any value, string type) {
	auto result = check_is_condition(words, value, type);
	if (result.has_value()) {
		return result.value();
	}
	return check_as_condition(words, value, type);
}

std::optional<bool> Runner::check_is_condition(Splitted_Line& words, any value, string type) {
	if (words.get_word() != "is") {
		return {};
	}
	words.increment_index();
	if (words.get_word() == "_") {
		return true;
	}
	if (type != words.get_word()) {
		return false;
	}
	words.increment_index();
	auto check_in_result=check_in_condition(words, value, type);
	if (check_in_result.has_value()) {
		return check_in_result.value();
	}
	auto result = *check_compare_condition(words, value, type).get();
	return result;
}

std::optional<bool> Runner::check_in_condition(Splitted_Line& words, any value, string type) {
	if (words.get_word() != "in") {
		return {};
	}
	words.increment_index();
	auto colection_check_result = check_in_colection_condition(words, value, type);
	if (colection_check_result) {
		return *colection_check_result.get();
	}
	auto zone_check_result = check_in_zone_condition(words, value, type);
	return *zone_check_result.get();
}

shared_ptr<char> Runner::check_in_colection_condition(Splitted_Line& words, any value, string type) {
	shared_ptr<char> result;
	if (type == "(char") {
		auto char_value = make_shared<char>(any_cast<char>(value));
		result = compare_with_colection<char>(char_value, words, &Runner::create_char_value);
	}
	if (type == "(float") {
		auto float_value = make_shared<double>(any_cast<double>(value));
		result = compare_with_colection<double>(float_value, words, &Runner::create_float_value);
	}
	if (type == "(int") {
		auto int_value = make_shared<long long int>(any_cast<long long int>(value));
		result = compare_with_colection<long long int>(int_value, words, &Runner::create_int_value);
	}
	if (type == "(string") {
		auto string_value = make_shared<string>(any_cast<string>(value));
		result = compare_with_colection<string>(string_value, words, &Runner::create_string_value);
	}
	return result;
}

shared_ptr<char> Runner::check_in_zone_condition(Splitted_Line& words, any value, string type) {
	shared_ptr<char> result;
	if (type == "(char") {
		auto char_value = make_shared<char>(any_cast<char>(value));
		result = compare_with_zone<char>(char_value, words, &Runner::create_char_value);
	}
	if (type == "(float") {
		auto float_value = make_shared<double>(any_cast<double>(value));
		result = compare_with_zone<double>(float_value, words, &Runner::create_float_value);
	}
	if (type == "(int") {
		auto int_value = make_shared<long long int>(any_cast<long long int>(value));
		result = compare_with_zone<long long int>(int_value, words, &Runner::create_int_value);
	}
	if (type == "(string") {
		auto string_value = make_shared<string>(any_cast<string>(value));
		result = compare_with_zone<string>(string_value, words, &Runner::create_string_value);
	}
	return result;
}

shared_ptr<char> Runner::check_compare_condition(Splitted_Line& words, any value, string type) {
	shared_ptr<char> result;
	auto _operator = words.get_word_and_increment_index();
	if (type == "(char") {
		auto char_value = make_shared<char>(any_cast<char>(value));
		auto second_value= create_char_value(words);
		result = Operations::compare(char_value, second_value, _operator);
	}
	if (type == "(float") {
		auto float_value = make_shared<double>(any_cast<double>(value));
		auto second_value = create_float_value(words);
		result = Operations::compare(float_value, second_value, _operator);
	}
	if (type == "(int") {
		auto int_value = make_shared<long long int>(any_cast<long long int>(value));
		auto second_value = create_int_value(words);
		result = Operations::compare(int_value, second_value, _operator);
	}
	if (type == "(string") {
		auto string_value = make_shared<string>(any_cast<string>(value));
		auto second_value = create_string_value(words);
		result = Operations::compare(string_value, second_value, _operator);
	}
	return result;
}

bool Runner::check_as_condition(Splitted_Line& words, any value, string type) {
	auto name = words.get_word();
	words.increment_index(2);
	if (type == '(' + words.get_word()) {
		return true;
	}
	auto new_type = words.get_word();
	auto convertion = As_Converters::convert(value, type, new_type);
	if (convertion.has_value()) {
		shared_ptr<void> remade_value=nullptr;
		if (new_type == "char") {
			remade_value = make_shared<char>(any_cast<char>(convertion));
		}
		if (new_type == "float") {
			remade_value = make_shared<double>(any_cast<double>(convertion));
		}
		if (new_type == "int") {
			remade_value = make_shared<long long int>(any_cast<long long int>(convertion));
		}
		if (new_type == "string") {
			remade_value = make_shared<string>(any_cast<string>(convertion));
		}
		vars.emplace(name, remade_value);
		return true;
	}
	return false;
}

bool Runner::execute_conditional(Splitted_Line &words) {
	if (words.get_word(0) != "CONDITIONAL") {
		return false;
	}
	bool executed = false;
	do{
		get_next_line();
		auto next_words = Splitted_Line(line);
		executed= execute_if(next_words);
		executed= executed||execute_else(next_words);
	}while (!executed && line!= "CONDITIONAL_END");
	if (executed) {
		skip_scope("CONDITIONAL", "CONDITIONAL_END");
	}
	return true;
}

bool Runner::execute_if(Splitted_Line& words) {
	if (words.get_word(0) != "IF") {
		return false;
	}
	words.increment_index();
	if (check_condition(words)) {
		execute_scope("IF_END");
		return true;
	}
	skip_scope("IF", "IF_END");
	return false;
	
}

bool Runner::execute_else(Splitted_Line& words) {
	if (words.get_word(0) != "ELSE") {
		return false;
	}
	execute_scope("ELSE_END");
	return true;
}

bool Runner::execute_while(Splitted_Line& words) {
	if (words.get_word(0) != "WHILE") {
		return false;
	}
	words.increment_index();
	auto conditional = words;
	auto start_pos = executive.get_position();
	while (check_condition(words)) {
		execute_scope("WHILE_END");
		executive.set_position(start_pos);
		words = conditional;
	}
	skip_scope("WHILE", "WHILE_END");
	return true;
}

bool Runner::check_condition(Splitted_Line& words) {
	if (words.get_word() == "(char") {
		words.increment_index();
		auto value = create_char_value(words);
		return (*value.get()) != '\0';
	}
	if (words.get_word() == "(float") {
		words.increment_index();
		auto value = create_float_value(words);
		return (*value.get()) != 0.0;
	}
	if (words.get_word() == "(int") {
		words.increment_index();
		auto value = create_int_value(words);
		return (*value.get()) != 0;
	}
	if (words.get_word() == "(string") {
		words.increment_index();
		auto value = create_string_value(words);
		return (*value.get()) != "";
	}
	return false;
}

int Runner::run(){
	executive.set_position(function_jumps["main"]);
	execute_scope("FUNCTION_END");
	auto returned = std::any_cast<long long int>(return_value("int"));
	_register = {};
	return returned;
}

char Run_Functions::create_const_char(string &word) {
	return word[1];
}

double Run_Functions::create_const_float(string &word) {
	return std::stod(word);
}

long long int Run_Functions::create_const_int(string &word) {
	return std::stoll(word);
}

std::string Run_Functions::create_const_string(string &word) {
	return word;
}
