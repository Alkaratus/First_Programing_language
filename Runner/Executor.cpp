#include "Executor.h"
#include "Operations.h"
#include "Library_Functions.h"
#include "Runner.h"
#include "As_converters.h"

using std::get, std::make_shared;

const shared_ptr<char> def = nullptr;

Executor::Executor(Validated_Object_Tree _tree) :
	return_register(def),
	operation_register(def),
	scope_executed(false),
	tree(_tree),
	main_index(0),
	preparation(false),
	return_called(false),
	condition_flag(false),
	as_variable_name(""){
	prepere_to_execute();
}

//Out: operation_register
void Executor::create_variable_value(shared_ptr<Operative_Object> value){
	auto buffer = preparation;
	preparation = false;
	value->accept(*this);
	preparation = buffer;
}

//Out: operation_register
void Executor::execute_operation(value first, value second, Operator_Type::type type){
	switch (type) {
	case Operator_Type::assign: {
		std::visit(Assign{}, first, second);
		return;
	}
	case Operator_Type::equal: {
		operation_register = std::visit(Equal{}, first, second);
		return;
	}
	case Operator_Type::not_equal: {
		operation_register = std::visit(Not_Equal{}, first, second);
		return;
	}
	case Operator_Type::grader_or_equal: {
		operation_register = std::visit(Grader_Or_Equal{}, first, second);
		return;
	}
	case Operator_Type::grader_than: {
		operation_register = std::visit(Grader_Than{}, first, second);
		return;
	}
	case Operator_Type::less_or_equal: {
		operation_register = std::visit(Less_Or_Equal{}, first, second);
		return;
	}
	case Operator_Type::less_than: {
		operation_register = std::visit(Less_Than{}, first, second);
		return;
	}
	case Operator_Type::summation: {
		operation_register = std::visit(Summation{}, first, second);
		return;
	}
	case Operator_Type::division: {
		operation_register = std::visit(Division{}, first, second);
		return;
	}
	case Operator_Type::modulation: {
		operation_register = std::visit(Modulation{}, first, second);
		return;
	}
	case Operator_Type::multiplication: {
		operation_register = std::visit(Multiplication{}, first, second);
		return;
	}
	case Operator_Type::subtraction: {
		operation_register = std::visit(Subtraction{}, first, second);
		return;
	}
	case Operator_Type::bin_and: {
		operation_register = std::visit(Bin_And{}, first, second);
		return;
	}
	case Operator_Type::bin_or: {
		operation_register = std::visit(Bin_Or{}, first, second);
		return;
	}
	case Operator_Type::bin_xor: {
		operation_register = std::visit(Bin_Xor{}, first, second);
		return;
	}
	case Operator_Type::shift_left: {
		operation_register = std::visit(Shift_Left{}, first, second);
		return;
	}
	case Operator_Type::shift_right: {
		operation_register = std::visit(Shift_Right{}, first, second);
		return;
	}
	case Operator_Type::_or: {
		operation_register = std::visit(_Or{}, first, second);
		return;
	}
	case Operator_Type::_and: {
		operation_register = std::visit(_And{}, first, second);
		return;
	}
	}
}

//Out: return_register;
void Executor::execute_lib_function(Function_Call_Object& function_call) {
	std::vector<shared_ptr<void>> arguments;
	for (auto& argument : function_arguments) {
		auto argument_value = argument.get_value();
		argument_value->accept(*this);
		switch (argument.get_value()->get_type().get_concrete()) {
		case Data_Type::_char: {
			arguments.push_back(get<shared_ptr<char>>(operation_register));
			break;
		}
		case Data_Type::_float: {
			arguments.push_back(get<shared_ptr<double>>(operation_register));
			break;
		}
		case Data_Type::_int: {
			arguments.push_back(get<shared_ptr<long long int>>(operation_register));
			break;
		}
		case Data_Type::_string: {
			arguments.push_back(get<shared_ptr<string>>(operation_register));
			break;
		}
		}
	}
	return_register = Library::get_function(function_call.get_name())(arguments);
}

bool Executor::check_condition(Data_Type::type type){
	value compared_value;
	switch (type) {
	case Data_Type::_char: {
		compared_value = make_shared<char>('\0');
		break;
	}
	case Data_Type::_float: {
		compared_value = make_shared<double>(0.0);
		break;
	}
	case Data_Type::_int: {
		compared_value = make_shared<long long int>(0);
		break;
	}
	case Data_Type::_string: {
		compared_value = make_shared<string>("");
		break;
	}
	}
	return *get<shared_ptr<char>>(std::visit(Not_Equal{}, operation_register, compared_value)).get();
}

value Executor::create_copy(Data_Type::type type){
	switch (type) {
	case Data_Type::_char: {
		return Run_Functions::create_copy<char>(get<shared_ptr<char>>(operation_register));
	}
	case Data_Type::_float: {
		return Run_Functions::create_copy<double>(get<shared_ptr<double>>(operation_register));
	}
	case Data_Type::_int: {
		return Run_Functions::create_copy<long long int>(get<shared_ptr<long long int>>(operation_register));
	}
	case Data_Type::_string: {
		return Run_Functions::create_copy<string>(get<shared_ptr<string>>(operation_register));
	}
	}
	return shared_ptr<char>(0);
}

value Executor::return_default(Data_Type::type type){
	switch (type) {
	case Data_Type::_char: {
		return make_shared<char>('\0');
	}
	case Data_Type::_float: {
		return make_shared<double>(0.0);
	}
	case Data_Type::_int: {
		return make_shared<long long int>(0);
	}
	case Data_Type::_string: {
		return make_shared<string>("");
	}
	}
	return shared_ptr<char>(0);
}

void Executor::visit(Conditional_Object& conditional){
	auto if_statements=conditional.get_if_statements();
	unsigned int i = 0;
	while ((!scope_executed)&&i<if_statements.size()) {
		if_statements[i].accept(*this);
		i++;
	}
	if (!scope_executed) {
		auto else_statement = conditional.get_else_statement();
		if (else_statement.has_value()) {
			else_statement.value().accept(*this);
		}
	}
	scope_executed = false;
}

void Executor::visit(Declarations_Object& declarations){
	for (auto& declaration : declarations.get_declarations()) {
		visit(declaration);
	}
}

void Executor::visit(Inspect_Object& inspect){
	auto inspected = inspect.get_inspected();
	inspected->accept(*this);
	inspect_register = operation_register;
	inspected_type = inspected->get_type().get_concrete();
	auto all_options=inspect.get_options();
	unsigned int i = 0;
	while ((!scope_executed) && i < all_options.size()) {
		all_options[i]->accept(*this);
		i++;
	}
	scope_executed = false;
}

//Out: return_register, return_called;
void Executor::visit(Return_Object& _return){
	_return.get_returned()->accept(*this);
	return_register = operation_register;
	return_called = true;
}

void Executor::visit(Variable_Object& variable){
	create_variable_value(variable.get_value());
	if (preparation) {
		global_vars.emplace(variable.get_essence().get_name(), operation_register);
		return;
	}
	scope_variables.push_back(variable.get_essence().get_name());
	vars.emplace(variable.get_essence().get_name(), operation_register);
}

void Executor::visit(Scope_Object& scope){
	auto buffer = scope_variables;
	scope_variables.clear();
	auto i = 0;
	auto statements = scope.get_statements();
	while (i<statements.size() && !return_called) {
		statements[i]->accept(*this);
		i++;
	}
	for (auto& name : scope_variables) {
		vars.erase(name);
	}
	scope_variables = buffer;
}

void Executor::visit(Is_Conditional_Object& is_conditional){
	is_conditional.get_condition()->accept(*this);
}

// Out:: condition_flag
void Executor::visit(Compare_Conditional_Object& compare_conditional){
	if (inspected_type != compare_conditional.get_compared()->get_type().get_concrete()) {
		condition_flag = false;
		return;
	}
	compare_conditional.get_compared()->accept(*this);
	execute_operation(inspect_register, operation_register, compare_conditional.get_operator().get_type());
	if (*get<shared_ptr<char>>(operation_register).get()) {
		condition_flag = true;
		return;
	}
	condition_flag = false;
}

// Out:: condition_flag
void Executor::visit(Default_Conditional_Object& default_conditional){
	condition_flag = true;
}

// Out:: condition_flag
void Executor::visit(In_Conditional_Object& in_conditional){
	if (inspected_type != in_conditional.get_set()->get_type().get_concrete()) {
		condition_flag = false;
		return;
	}
	operation_register = inspect_register;
	in_conditional.get_set()->accept(*this);
	if (*get<shared_ptr<char>>(operation_register).get()) {
		condition_flag = true;
		return;
	}
	condition_flag = false;
}

// Out:: condition_flag, as_variable_name
void Executor::visit(As_Conditional_Object& as_conditional){
	auto new_type=as_conditional.get_type().get_concrete();
	any value;
	switch (inspected_type) {
	case Data_Type::_char: {
		value= *get<shared_ptr<char>>(operation_register).get();
		break;
	}
	case Data_Type::_float: {
		value = *get<shared_ptr<double>>(operation_register).get();
		break;
	}
	case Data_Type::_int: {
		value = *get<shared_ptr<long long int>>(operation_register).get();
		break;
	}
	case Data_Type::_string: {
		value = *get<shared_ptr<string>>(operation_register).get();
		break;
	}
	}
	value=As_Converters::convert(value, inspected_type, new_type);
	if (!value.has_value()) {
		condition_flag = false;
		return;
	}
	switch (new_type) {
	case Data_Type::_char: {
		auto new_value = make_shared<char>(std::any_cast<char>(value));
		vars.emplace(as_conditional.get_name(), new_value);
		break;
	}
	case Data_Type::_float: {
		auto new_value = make_shared<double>(std::any_cast<double>(value));
		vars.emplace(as_conditional.get_name(), new_value);
		break;
	}
	case Data_Type::_int: {
		auto new_value = make_shared<long long int>(std::any_cast<long long int>(value));
		vars.emplace(as_conditional.get_name(), new_value);
		break;
	}
	case Data_Type::_string: {
		auto new_value = make_shared<string>(std::any_cast<string>(value));
		vars.emplace(as_conditional.get_name(), new_value);
		break;
	}
	}
	scope_variables.push_back(as_conditional.get_name());
	as_variable_name = as_conditional.get_name();
	condition_flag = true;
}

//Out: Operation_Register
void Executor::visit(Variable_Call_Object& variable_call){
	operation_register= vars[variable_call.get_name()];
}

//Out: Operation_Register
void Executor::visit(Function_Call_Object& function_call){
	function_call.get_arguments();
	function_arguments = function_call.get_arguments();
	if (function_call.get_name()[0] == '@') {
		execute_lib_function(function_call);
		return;
	}
	auto function = tree.get_objects()[function_indexes[function_call.get_name()]];
	function->accept(*this);
	if (return_called) {
		operation_register = return_register;
	}
	else {
		operation_register = return_default(function_call.get_type().get_concrete());
	}
	return_called = false;
}

//Out: Operation_Register
void Executor::visit(Operation_Object& operation){
	operation.get_first_operative()->accept(*this);
	auto first = operation_register;
	operation.get_second_operative()->accept(*this);
	auto second = operation_register;
	execute_operation(first, second, operation.get_operator().get_type());
}

//Out: Operation_Register
void Executor::visit(In_Set_Object& in_set){
	in_set.get_checked()->accept(*this);
	in_set.get_set()->accept(*this);
}

//Out: Operation_Register
void Executor::visit(Char_Object& _char){
	operation_register = make_shared<char>(get<char>(_char.get_value()));
}

//Out: Operation_Register
void Executor::visit(Float_Object& _float){
	operation_register = make_shared<double>(get<double>(_float.get_value()));
}

//Out: Operation_Register
void Executor::visit(Int_Object& _int){
	operation_register = make_shared<long long int>(get<long long int>(_int.get_value()));
}

//Out: Operation_Register
void Executor::visit(String_Object& _string){
	operation_register = make_shared<string>(get<string>(_string.get_value()));
}

void Executor::visit(Function_Object& function){
	if (preparation) {
		function_indexes.emplace(function.get_name(), main_index);
		return;
	}
	auto function_vars = global_vars;
	auto arguments_essence = function.get_arguments();
	for (size_t i = 0; i < arguments_essence.size(); i++) {
		auto argument_value = function_arguments[i].get_value();
		argument_value->accept(*this);
		if (function_arguments[i].is_copy()) {
			operation_register = create_copy(function_arguments[i].get_value()->get_type().get_concrete());
		}
		function_vars.emplace(arguments_essence[i].get_name(), operation_register);
	}
	auto buffer = vars;
	vars = function_vars;
	function.get_scope().accept(*this);
	vars = buffer;
}

//Out: Scope_Executed
void Executor::visit(If_Object& _if){
	auto condition = _if.get_condition();
	condition->accept(*this);
	if (check_condition(condition->get_type().get_concrete())) {
		_if.get_scope().accept(*this);
		scope_executed = true;
	}
}

void Executor::visit(Else_Object& _else){
	_else.get_scope().accept(*this);
}

//Out: Scope_Executed
void Executor::visit(Inspect_Option_Object& inspect_option){
	auto buffer = as_variable_name;
	as_variable_name = "";
	inspect_option.get_condition()->accept(*this);
	if (!condition_flag) {
		as_variable_name = buffer;
		return;
	}
	inspect_option.get_scope().accept(*this);
	scope_executed = true;
	if (as_variable_name != "") {
		vars.erase(as_variable_name);
		as_variable_name = "";
	}
	condition_flag = false;
	as_variable_name = buffer;
}

void Executor::visit(While_Object& _while){
	auto condition = _while.get_condition();
	condition->accept(*this);
	while (check_condition(condition->get_type().get_concrete())) {
		_while.get_scope().accept(*this);
		condition->accept(*this);
	}
}

// In: Operation_Register
// Out: Operation_Register
void Executor::visit(Colection_Object& collection){
	auto compared = operation_register;
	for (auto& element : collection.get_colection()) {
		element->accept(*this);
		auto result=std::visit(Equal{}, compared, operation_register);
		if (*get<shared_ptr<char>>(result).get()) {
			operation_register = result;
			return;
		}
	}
	operation_register = make_shared<char>('\0');
}

// In: Operation_Register
// Out: Operation_Register
void Executor::visit(Zone_Object& zone){
	auto compared = operation_register;
	zone.get_left_end()->accept(*this);
	auto first_limit= operation_register;
	value result;
	if (zone.is_left_closed()) {
		result=std::visit(Less_Or_Equal{}, first_limit, compared);
	}
	else {
		result=std::visit(Less_Than{}, first_limit, compared);
	}
	if (!(*get<shared_ptr<char>>(result).get())) {
		operation_register = result;
		return;
	}
	zone.get_right_end()->accept(*this);
	auto second_limit = operation_register;
	if (zone.is_right_closed()) {
		result = std::visit(Less_Or_Equal{}, compared, second_limit);
	}
	else {
		result = std::visit(Less_Than{}, compared, second_limit);
	}
	operation_register = result;
}

void Executor::prepere_to_execute(){
	preparation = true;
	auto all_objects=tree.get_objects();
	for (main_index = 0; main_index < all_objects.size(); main_index++) {
		all_objects[main_index]->accept(*this);
	}
	main_index = function_indexes["main"];
	preparation = false;
}

void Executor::execute(){
	auto all_objects = tree.get_objects();
	all_objects[main_index]->accept(*this);
	
}

value Executor::get_var(string name){
	return vars[name];
}

value Executor::get_register(){
	return operation_register;
}

value Executor::get_return_register(){
	return return_register;
}
