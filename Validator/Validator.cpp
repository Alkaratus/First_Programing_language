#include "Validator.h"
#include <filesystem>
#include <stdexcept>
#include "../Parser/Real_Parser.h"

std::vector<std::pair<Data_Type::type, Operator_Type::type>> const aceptable_operations={
	{Data_Type::_char,Operator_Type::assign},
	{Data_Type::_float,Operator_Type::assign},
	{Data_Type::_int,Operator_Type::assign},
	{Data_Type::_string,Operator_Type::assign},

	{Data_Type::_char,Operator_Type::bin_and},
	{Data_Type::_int,Operator_Type::bin_and},

	{Data_Type::_char,Operator_Type::bin_or},
	{Data_Type::_int,Operator_Type::bin_or},

	{Data_Type::_char,Operator_Type::bin_xor},
	{Data_Type::_int,Operator_Type::bin_xor},

	{Data_Type::_char,Operator_Type::division},
	{Data_Type::_float,Operator_Type::division},
	{Data_Type::_int,Operator_Type::division},

	{Data_Type::_char,Operator_Type::equal},
	{Data_Type::_float,Operator_Type::equal},
	{Data_Type::_int,Operator_Type::equal},
	{Data_Type::_string,Operator_Type::equal},

	{Data_Type::_char,Operator_Type::grader_or_equal},
	{Data_Type::_float,Operator_Type::grader_or_equal},
	{Data_Type::_int,Operator_Type::grader_or_equal},
	{Data_Type::_string,Operator_Type::grader_or_equal},

	{Data_Type::_char,Operator_Type::grader_than},
	{Data_Type::_float,Operator_Type::grader_than},
	{Data_Type::_int,Operator_Type::grader_than},
	{Data_Type::_string,Operator_Type::grader_than},

	{Data_Type::_char,Operator_Type::less_or_equal},
	{Data_Type::_float,Operator_Type::less_or_equal},
	{Data_Type::_int,Operator_Type::less_or_equal},
	{Data_Type::_string,Operator_Type::less_or_equal},

	{Data_Type::_char,Operator_Type::less_than},
	{Data_Type::_float,Operator_Type::less_than},
	{Data_Type::_int,Operator_Type::less_than},
	{Data_Type::_string,Operator_Type::less_than},

	{Data_Type::_char,Operator_Type::modulation},
	{Data_Type::_int,Operator_Type::modulation},
	{Data_Type::_float,Operator_Type::modulation},

	{Data_Type::_char,Operator_Type::multiplication},
	{Data_Type::_int,Operator_Type::multiplication},
	{Data_Type::_float,Operator_Type::multiplication},

	{Data_Type::_char,Operator_Type::not_equal},
	{Data_Type::_float,Operator_Type::not_equal},
	{Data_Type::_int,Operator_Type::not_equal},
	{Data_Type::_string,Operator_Type::not_equal},

	{Data_Type::_char,Operator_Type::shift_left},
	{Data_Type::_int,Operator_Type::shift_left},

	{Data_Type::_char,Operator_Type::shift_right},
	{Data_Type::_int,Operator_Type::shift_right},

	{Data_Type::_char,Operator_Type::subtraction},
	{Data_Type::_int,Operator_Type::subtraction},
	{Data_Type::_float,Operator_Type::subtraction},

	{Data_Type::_char,Operator_Type::summation},
	{Data_Type::_int,Operator_Type::summation},
	{Data_Type::_float,Operator_Type::summation},
	{Data_Type::_string,Operator_Type::summation},

	{Data_Type::_char,Operator_Type::_and},

	{Data_Type::_char,Operator_Type::_or},
};

Validator::Validator(bool _test):
	test(_test), 
	was_include(false), 
	is_lib_file(false)
{}

Validator::Validator(Validator const& other):
	test(other.test), 
	was_include(false), 
	is_lib_file(false), 
	validated_tree(other.validated_tree.get_tree_without_objects())
{}

void Validator::manage_included_file(std::shared_ptr<Source_File>source){
	Source_Lexer lexer(*source);
	Real_Parser parser(lexer);
	auto tree = parser.parse_all();
	Validator new_validator;
	new_validator.is_lib_file = is_lib_file;
	auto new_tree = new_validator.validate_tree(tree);
	validated_tree += new_tree;
	
}

void Validator::validate_and_check_type(std::shared_ptr<Operative_Object> &operative, Data_Type::type expected_type){
	operative->accept(*this);
	if (expected_type != operative->get_type().get_concrete()) {
		raise_error(operative->get_position(), "Operative type and required type are not the same");
	}
}

std::string Validator::create_alias(std::string function_name){
	auto non_overload_new_name = (is_lib_file ? "@" : "") + function_name;
	auto new_name = non_overload_new_name;
	int i = 0;
	while (validated_tree.is_alias_in_functions(new_name)) {
		i++;
		new_name = non_overload_new_name + std::to_string(i);
	}
	return new_name;
}


void Validator::visit(Conditional_Object& conditional) {
	for (auto if_statement : conditional.get_if_statements()) {
		visit(if_statement);
	}
	auto else_statement = conditional.get_else_statement();
	if (else_statement.has_value()) {
		visit(else_statement.value());
	}
}

void Validator::visit(Declarations_Object& declarations) {
	for (auto &declaration: declarations.get_declarations()) {
		visit(declaration);
	}
}

void Validator::visit(Include_Object& include) {
	auto file_name = include.get_name();
	std::string lib_dir_path = (test ? "../../" : "");
	lib_dir_path += "../../../../Libraries/";
	if (validated_tree.is_included(file_name)!=-1) {
		was_include = true;
		return;
	}
	auto opened_file = try_open_file(lib_dir_path + file_name);
	if (opened_file) {
		if (try_open_file(include.get_position().get_file().get_directory() + file_name)) {
			raise_error(include.get_position(), "Name conflict between library and user-created files");
		}
		is_lib_file = true;
	}
	else {
		opened_file = try_open_file(include.get_position().get_file().get_directory() + file_name);
		if (!opened_file) {
			raise_error(include.get_position(), "Included file wasn't found");
		}
	}
	manage_included_file(opened_file);
	is_lib_file = false;
	validated_tree.add_included(file_name, false);
	was_include = true;
	return;
	
}

void Validator::visit(Inspect_Object& inspect) {
	inspect.get_inspected()->accept(*this);
	for (auto& option : inspect.get_options()) {
		option->accept(*this);
	}
}

void Validator::visit(Return_Object& _return) {
	validate_and_check_type(_return.get_returned(), validated_tree.get_last_function().get_type().get_concrete());
}

void Validator::visit(Variable_Object &variable) {
	if (validated_tree.is_in_variables(variable.get_essence().get_name())!=-1 || validated_tree.is_in_functions(variable.get_essence().get_name())!= -1){
		raise_error(variable.get_position(), "Variable of Function with that name already exist");
	}
	auto initializator = variable.get_value();
	initializator->accept(*this);
	if (variable.get_essence().get_type().get_concrete() == Data_Type::_auto) {
		variable.get_essence().set_type(initializator->get_type());
	}
	else if (variable.get_essence().get_type().get_concrete() != initializator->get_type().get_concrete()) {
		raise_error(initializator->get_position(), "Variable and initializator have differend types");
	}
	validated_tree.add_variable(variable);
}


void Validator::visit(Scope_Object& scope){
	for (auto statement : scope.get_statements()) {
		statement->accept(*this);
	}
}


void Validator::visit(Is_Conditional_Object& is_conditional){
	is_conditional.get_condition()->accept(*this);
}

void Validator::visit(Compare_Conditional_Object& compare_conditional){
	auto const accepted_operators = {
		Operator_Type::equal,
		Operator_Type::not_equal,
		Operator_Type::grader_or_equal,
		Operator_Type::grader_than,
		Operator_Type::less_or_equal,
		Operator_Type::less_than
	};
	bool acceptable = false;
	for (auto& _operator : accepted_operators) {
		if (compare_conditional.get_operator().get_type() == _operator) {
			acceptable = true;
		}
	}
	if (!acceptable) {
		raise_error(compare_conditional.get_position(), "Used operator is not aceptable");
	}
}

void Validator::visit(In_Conditional_Object& in_conditional){
	in_conditional.get_set()->accept(*this);
}

void Validator::visit(As_Conditional_Object& as_conditional){
	if (validated_tree.is_in_variables(as_conditional.get_name()) != -1 || validated_tree.is_in_functions(as_conditional.get_name()) != -1) {
		raise_error(as_conditional.get_position(), "Variable or Function with that name already exist");
	}
	validated_tree.add_variable(as_conditional);
}


void Validator::visit(Function_Object &function) {
	if (validated_tree.is_in_functions(function)!=-1 || validated_tree.is_in_variables(function.get_name())!=-1) {
		raise_error(function.get_position(), "Variable with that name or Function with that name and arguments already exist");
	}
	auto alias= create_alias(function.get_name());
	validated_tree.add_function(function, alias);
	function.set_name(alias);
	Validator temporary = *this;
	for (auto argument : function.get_arguments()) {
		temporary.validated_tree.add_variable(Located_Variable_Essence(function.get_position().get_file().get_file_name(), argument));
	}
	temporary.visit(function.get_scope());
}

void Validator::visit(If_Object& _if) {
	_if.get_condition()->accept(*this);
	Validator temporary = *this;
	temporary.visit(_if.get_scope());
}

void Validator::visit(Else_Object& _else) {
	Validator temporary = *this;
	temporary.visit(_else.get_scope());
}

void Validator::visit(Inspect_Option_Object& inspect_option_object){
	Validator temporary = *this;
	inspect_option_object.get_condition()->accept(temporary);
	temporary.visit(inspect_option_object.get_scope());
}

void Validator::visit(While_Object& _while){
	_while.get_condition()->accept(*this);
	Validator temporary = *this;
	temporary.visit(_while.get_scope());
}


void Validator::visit(Colection_Object& collection){
	auto &elements = collection.get_colection();
	if (!elements.size()) {
		return;
	}
	elements[0]->accept(*this);
	for (auto i = 1; i < elements.size(); i++) {
		validate_and_check_type(elements[i], elements[0]->get_type().get_concrete());
	}
	collection.set_type(elements[0]->get_type());
}

void Validator::visit(Zone_Object& zone){
	auto &left_end = zone.get_left_end();
	left_end->accept(*this);
	validate_and_check_type(zone.get_right_end(), left_end->get_type().get_concrete());
	zone.set_type(left_end->get_type());
}


void Validator::visit(Variable_Call_Object &variable_call) {
	auto variable_index = validated_tree.is_in_variables(variable_call.get_name());
	if (variable_index ==-1) {
		raise_error(variable_call.get_position(), "Variable with that name not exist");
	}
	variable_call.set_type(validated_tree.get_variable(variable_index).get_type().get_concrete());
	variable_call.set_l_value(!validated_tree.get_variable(variable_index).is_constans());
}

void Validator::visit(Function_Call_Object &function_call) {
	for (auto& argument : function_call.get_arguments()) {
		argument.get_value()->accept(*this);
	}
	auto function_index = validated_tree.is_in_functions(function_call);
	if (function_index == -1) {
		raise_error(function_call.get_position(), "Function with that name and arguments not exist");
	}
	function_call.set_name(validated_tree.get_function(function_index).get_alt_name());
	function_call.set_type(validated_tree.get_function(function_index).get_type().get_concrete());
}

void Validator::visit(Operation_Object &operation) {
	auto first_operative = operation.get_first_operative();
	first_operative->accept(*this);
	auto second_operative = operation.get_second_operative();
	second_operative->accept(*this);
	if (first_operative->get_type().get_concrete() != second_operative->get_type().get_concrete()) {
		raise_error(second_operative->get_position(), "Operatives data_types not match, use converters to make it");
	}
	if (!is_possible_operation(first_operative->get_type().get_concrete(), operation.get_operator().get_type())){
		raise_error(second_operative->get_position(), "Opperation cannot be made for operatives of this type");
	}
	if (operation.get_operator().get_type()==Operator_Type::assign && !first_operative->is_l_value()) {
		raise_error(second_operative->get_position(), "Value cannot be assign to constans");
	}
	operation.set_type(set_operation_result_type(first_operative->get_type().get_concrete(), operation.get_operator().get_type()));
}

void Validator::visit(In_Set_Object& in_set){
	auto checked = in_set.get_checked();
	auto set = in_set.get_set();
	set->accept(*this);
	if (set->get_type().get_concrete() == Data_Type::_void) {
		show_warning(set->get_position(), "Colection is empty, operation will be always false");
		checked->accept(*this);
	}
	else {
		validate_and_check_type(checked, set->get_type().get_concrete());
	}
}

Validated_Object_Tree Validator::get_current_tree(){
	return validated_tree;
}

Validated_Object_Tree Validator::validate_tree(Object_Tree tree) {
	validated_tree = Validated_Object_Tree();
	auto parsed_objects = tree.get_objects();
	for (auto object :parsed_objects) {
		object->accept(*this);
		if (was_include) {
			was_include = false;
		}
		else {
			validated_tree.add_object(object);
		}
	}
	return validated_tree;
}

std::shared_ptr<Source_File> try_open_file(std::string file_name){
	try {
		return std::make_shared<Source_File>(Source_File(file_name));
	}
	catch (std::invalid_argument&) {
		return nullptr;
	}
}

bool is_possible_operation(Data_Type::type data_type, Operator_Type::type operator_type){
	for (auto& acceptable_operation : aceptable_operations) {
		if (acceptable_operation.first == data_type && acceptable_operation.second ==operator_type) {
			return true;
		}
	}
	return false;
}

Data_Type::type set_operation_result_type(Data_Type::type data_type, Operator_Type::type operator_type){
	if (operator_type >= Operator_Type::multiplication && operator_type <= Operator_Type::shift_right) {
		return data_type;
	}
	if (operator_type >= Operator_Type::grader_than && operator_type <= Operator_Type::_or) {
		return Data_Type::_char;
	}
	return Data_Type::_void;
}
