#include <map>
#include "Parser.h"
#include "../Objects/Operatives/In_Set_Object.h"
#include "../Objects/Inspect_Conditionals/Inspect_Is_Conditionals/Default_Conditional_Object.h"
#include "../Objects/Inspect_Conditionals/Inspect_Is_Conditionals/Compare_Conditional_Object.h"
#include "../Objects/Inspect_Conditionals/Inspect_Is_Conditionals/In_Conditional_Object.h"
#include "../Objects/Dependent/Type_Object.h"

using std::make_shared;

Parser::Parser(Lexer& _lexer):
	lexer(_lexer),
	buffer(lexer.get_token())
{}

bool Parser::is(Token::token_type type) const {
	return buffer.get_type() == type;
}

void Parser::expect(Token::token_type expected, std::string message_if_invalid) {
	if (!is(expected)) {
		raise_error(buffer.get_position(), message_if_invalid);
	}
}

void Parser::expect(std::vector<Token::token_type> const expecteds, std::string message_if_invalid) {
	for (auto& expected : expecteds) {
		if (is(expected)) {
			return;
		}
	}
	raise_error(buffer.get_position(), message_if_invalid);
}

void Parser::expect(bool (Token::* method)() const, std::string message_if_invalid) {
	if (!(buffer.*method)()) {
		raise_error(buffer.get_position(), message_if_invalid);
	}
}

bool Parser::consume_if(Token::token_type possible) {
	if (is(possible)) {
		buffer = lexer.get_token();
		return true;
	}
	return false;
}

bool Parser::is_lexer_end() {
	return lexer.is_end();
}

// Scope= "{", {statement},"}";
Scope_Object Parser::create_scope() {
	Scope_Object objects;
	expect(Token::open_buckle, "Invalid token");
	buffer = lexer.get_token();
	while (!is(Token::close_buckle)) {
		consume_if(Token::semicolon);
		if (!is(Token::close_buckle)) {
			objects.add_statement(parse_in_scope());
		}
	}
	buffer = lexer.get_token();
	return objects;
}

// Start= Include| Declaration| Function_Definition;
shared_ptr<Compilation_Object> Parser::parse(){
	auto include = create_include_object();
	if (include) {
		consume_if(Token::semicolon);
		return include;
	}
	auto void_function = create_void_function();
	if (void_function) {
		return void_function;
	}
	auto auto_variable = create_auto_variable_object();
	if (auto_variable) {
		consume_if(Token::semicolon);
		return auto_variable;
	}
	auto type_started_object = create_type_start_object();
	if (type_started_object) {
		consume_if(Token::semicolon);
		return type_started_object;
	}
	raise_error(buffer.get_position(), "Token is not start of any statement");
}

// Statement=Declaration|Name_Started_Statement|Loop|Conditional_instruction|Return;
shared_ptr<Compilation_Object> Parser::parse_in_scope(){
	std::shared_ptr<Compilation_Object> object;
	object = create_auto_variable_object();
	if (object) {
		return object;
	}
	object = create_declarations_object();
	if (object) {
		return object;
	}
	object = create_conditional_object();
	if (object) {
		return object;
	}
	object = create_while_object();
	if (object) {
		return object;
	}
	object = create_inspect_object();
	if (object) {
		return object;
	}
	object = create_return_object();
	if (object) {
		return object;
	}
	object = create_name_start_object();
	if (object) {
		return object;
	}
	raise_error(buffer.get_position(), "Token is not start of any statement");
}


// Include = ”include”, Text, ";";
shared_ptr<Include_Object> Parser::create_include_object(){
	if (!is(Token::include)) {
		return nullptr;
	}
	auto include_token= buffer;
	buffer =lexer.get_token();
	expect(Token::const_string, "Unexpected token, expected name");
	auto name_token = buffer;
	buffer = lexer.get_token();
	expect(Token::semicolon, "Missed semicolon");
	return make_shared<Include_Object>(Include_Object(include_token.get_position(), std::get<std::string>(name_token.get_value())));
}

// Function_Definition= ”void”,Name, ”(”, List_Of_Arguments, ”)”, Scope;
shared_ptr<Function_Object> Parser::create_void_function() {
	if (!is(Token::_void)) {
		return nullptr;
	}
	buffer = lexer.get_token();
	expect(Token::name);
	auto name_token = buffer;
	buffer = lexer.get_token();
	expect(Token::open_bracket);
	auto arguments=create_list_of_arguments();
	shared_ptr <Function_Object>new_function=make_shared<Function_Object>(Function_Object(buffer.get_position(), Data_Type_Object(Token::_void), std::get<std::string>(name_token.get_value()), arguments));
	buffer = lexer.get_token();
	new_function->set_scope(create_scope()); 
	return new_function;
}

// Auto_Variable_Declaration = "auto", [”var”], Name, ”=”, Operative,";";
shared_ptr<Variable_Object> Parser::create_auto_variable_object() {
	if (!is(Token::_auto)) {
		return nullptr;
	}
	buffer = lexer.get_token();
	bool is_var = consume_if(Token::var);
	expect(Token::name, "Invalid token, expected name");
	auto const name = std::get<std::string>(buffer.get_value());
	buffer = lexer.get_token();
	expect(Token::assign, "Auto-type variable have to be initialized");
	buffer = lexer.get_token();
	auto operative = create_operative_object();
	expect(Token::semicolon, "Missed semicolon");
	return make_shared<Variable_Object>(Variable_Object(buffer.get_position(), Variable_Essence(operative->get_type(), name, !is_var), operative ));
}

// Function_Definition | Type_Variable_Declaration
shared_ptr<Compilation_Object> Parser::create_type_start_object() {
	if (!buffer.is_variable_type()) {
		return nullptr;
	}
	auto type = buffer.get_type();
	buffer = lexer.get_token();
	auto variables= create_variable_begin_declarations_object(type);
	if (variables){
		return variables;
	}
	expect(Token::name, "Invalid token");
	auto name = buffer;
	buffer = lexer.get_token();
	auto function = create_function_object(type, name);
	if (function) {
		return function;
	}
	variables = create_constans_begin_declarations_object(type,name);
	if (variables) {
		return variables;
	}
	raise_error(buffer.get_position(), "Invalid_Token");
}

// Function_Definition= Type, Name, ”(”, List_Of_Arguments, ”)”, Scope;
shared_ptr<Function_Object> Parser::create_function_object(Token::token_type type, Token name) {
	if (!is(Token::open_bracket)) {
		return nullptr;
	}
	auto arguments = create_list_of_arguments();
	shared_ptr<Function_Object> new_function=make_shared<Function_Object>(Function_Object(buffer.get_position(), Data_Type_Object(type), std::get<std::string>(name.get_value()), arguments));
	buffer = lexer.get_token();
	new_function->set_scope(create_scope());
	return new_function;
}

// Type_Variable_Declaration = Type, ”var”, Name, [”=”, Operative], {Next_Variable},”;”;
shared_ptr<Declarations_Object> Parser::create_variable_begin_declarations_object(Token::token_type type) {
	if (!consume_if(Token::var)) {
		return nullptr;
	}
	std::vector<Variable_Object> variables;
	expect(Token::name);
	auto name_token = buffer;
	buffer = lexer.get_token();
	std::shared_ptr<Operative_Object>value;
	if (buffer.get_type() == Token::assign) {
		value=create_operative_object();
	}
	else {
		value = default_value(type);
	}
	expect({ Token::comma ,Token::semicolon });
	variables.push_back(Variable_Object(name_token.get_position(), Variable_Essence(type, std::get<std::string>(name_token.get_value()), false), value));
	while (!is(Token::semicolon)){
		variables.push_back(create_next_variable(type));
	} 
	return make_shared<Declarations_Object>(Declarations_Object(name_token.get_position(), variables));
}

// Type_Variable_Declaration = Type, Name, [”=”, Operative], {Next_Variable},”;”;
shared_ptr<Declarations_Object> Parser::create_constans_begin_declarations_object(Token::token_type type, Token name) {
	std::vector<Variable_Object> variables;
	if (buffer.get_type() != Token::assign && buffer.get_type() != Token::semicolon) {
		return nullptr;
	}
	std::shared_ptr<Operative_Object>value;
	if (buffer.get_type() == Token::assign) {
		buffer = lexer.get_token();
		value = create_operative_object();
	}
	else {
		value = default_value(type);
	}
	expect({ Token::comma ,Token::semicolon });
	variables.push_back(Variable_Object(name.get_position(), Variable_Essence(Data_Type_Object(type), std::get<std::string>(name.get_value()), true), value ));
	while (buffer.get_type() != Token::semicolon) {
		variables.push_back(create_next_variable(type));
	}
	return make_shared<Declarations_Object>(Declarations_Object(name.get_position(), variables));
}

// Next_Variable = [”var”], Name, [” = ”, Operative]
Variable_Object Parser::create_next_variable(Token::token_type type) {
	buffer = lexer.get_token();
	bool is_var = consume_if(Token::var);
	expect(Token::name, "Invalid token, expected name");
	auto name_token = buffer;
	buffer = lexer.get_token();
	std::shared_ptr<Operative_Object>value;
	if (is(Token::assign)) {
		buffer = lexer.get_token();
		value = create_operative_object();
	}
	else {
		value = default_value(type);
	}
	expect({ Token::comma ,Token::semicolon });
	return (Variable_Object(name_token.get_position(), Variable_Essence(type, std::get<std::string>(name_token.get_value()), !is_var), value));
}

// List_Of_Arguments = [{Type, [”var”], Name, ”, ”}, [Type, [”var”], Name]]
std::vector<Variable_Essence> Parser::create_list_of_arguments() {
	std::vector<Variable_Essence> arguments;
	buffer = lexer.get_token();
	while (buffer.get_type() != Token::close_bracket) {
		expect(&Token::is_variable_type);
		auto argument_type = buffer.get_type();
		buffer = lexer.get_token();
		bool is_var = consume_if(Token::var);
		expect(Token::name, "Invalid token");
		arguments.push_back(Variable_Essence(argument_type, std::get<std::string>(buffer.get_value()), !is_var));
		buffer = lexer.get_token();
		expect({ Token::comma ,Token::close_bracket });
		if (buffer.get_type() == Token::comma) {
			buffer = lexer.get_token();
		}
	}
	return arguments;
}

// Single_Operative = Call|Constans;
shared_ptr<Operative_Object> Parser::create_single_operative_object() {
	auto buffer_value = buffer;
	auto call = create_call_object();
	if (call) {
		return call;
	}
	auto constans = create_cosntans_object();
	if (constans) {
		buffer = lexer.get_token();
		return constans;
	}
	raise_error(buffer_value.get_position(), "Unexpected token, expected name or constans value");
	return nullptr;
}

// Constans = Char | Text | Intiger | Float;
shared_ptr<Constans_Object> Parser::create_cosntans_object(){
	shared_ptr<Constans_Object> object;
	object = create_string_object();
	if (object) { 
		return object; 
	}
	object = create_char_object();
	if (object) {
		return object;
	}
	object = create_numeric_object();
	return object;
	
}

// String
shared_ptr<String_Object> Parser::create_string_object() {
	if (!is(Token::const_string)) {
		return nullptr;
	}
	return std::make_shared<String_Object>(String_Object(buffer.get_position(), std::get<std::string>(buffer.get_value())));
}

// Char
shared_ptr<Char_Object> Parser::create_char_object() {
	if (!is(Token::const_char)) {
		return nullptr;
	}
	return std::make_shared<Char_Object>(Char_Object(buffer.get_position(), std::get<char>(buffer.get_value())));
}

// Float | Int
shared_ptr<Constans_Object> Parser::create_numeric_object() {
	bool is_minus = consume_if(Token::subtraction);
	shared_ptr<Constans_Object> object=create_float_object(is_minus);
	if (object) {
		return object;
	}
	object = create_int_object(is_minus);
	return object;
	
}

//Float
shared_ptr<Float_Object> Parser::create_float_object(bool minus) {
	if (!is(Token::const_float)) {
		return nullptr;
	}
	auto value = std::get<double>(buffer.get_value());
	value = minus ? value * (-1) : value ;
	return std::make_shared<Float_Object>(Float_Object(buffer.get_position(), value));
}

// Int
shared_ptr<Int_Object> Parser::create_int_object(bool minus) {
	if (!is(Token::const_int)) {
		return nullptr;
	}
	auto value = std::get<long long int>(buffer.get_value());
	value = minus ? value * (-1) : value ;
	return std::make_shared<Int_Object>(Int_Object(buffer.get_position(), value));
}

// Call = Function_Call | Variable_Call;
shared_ptr<Operative_Object> Parser::create_call_object() {
	if (!is(Token::name)) {
		return nullptr;
	}
	auto name_token = buffer;
	buffer = lexer.get_token();
	auto function = create_function_call_object(name_token);
	if (function) {
		return function;
	}
	auto variable = create_variable_call_object(name_token);
	return variable;
}

// Variable_Call = Name;
shared_ptr<Variable_Call_Object> Parser::create_variable_call_object(Token name){
	return std::make_shared<Variable_Call_Object>(Variable_Call_Object(name.get_position(), std::get<std::string>(name.get_value())));
}

// Function_Call = Name,”(”, [{[#],Operative},”,”}, [#]Operative], ”)”,”;”;
shared_ptr<Function_Call_Object> Parser::create_function_call_object(Token name) {
	if (!is(Token::open_bracket)) {
		return nullptr;
	}
	std::vector<Function_Argument>arguments;
	buffer = lexer.get_token();
	while (!is(Token::close_bracket)) {
		consume_if(Token::comma);
		bool is_hash = consume_if(Token::hash);
		arguments.push_back(Function_Argument(is_hash,create_operative_object()));
		expect({ Token::comma, Token::close_bracket });
	}
	buffer = lexer.get_token();
	return std::make_shared<Function_Call_Object>(Function_Call_Object(name.get_position(), std::get<std::string>(name.get_value()), arguments));
}

// Operative= Atomic_Operative | Log_Or | In_Set; 
shared_ptr<Operative_Object> Parser::create_operative_object(){
	auto operative = check_bracket_and_create_operative();
	auto new_operative= create_operation_object(operative,false);
	if (new_operative) {
		operative = new_operative;
	}
	new_operative = create_in_set_object(operative);
	if (new_operative) {
		operative = new_operative;
	}
	return operative;
}

// Operation = Assign | Log_Or;
shared_ptr<Operative_Object> Parser::create_operation_object(shared_ptr<Operative_Object> object, bool can_be_assign) {
	if (!buffer.is_operator_type()) {
		return nullptr;
	}
	Token operator_token = buffer;
	buffer = lexer.get_token();
	auto next_object = check_bracket_and_create_operative();
	auto next_operator_priority = operator_priority(buffer,false);
	while (next_operator_priority < 11) {
		if (operator_priority(operator_token, can_be_assign) <= next_operator_priority) {
			object = std::make_shared<Operation_Object>(Operation_Object(object->get_position(), object, operator_token.get_type(), next_object));
			operator_token = buffer;
			buffer = lexer.get_token();
			next_object = check_bracket_and_create_operative();
			next_operator_priority = operator_priority(buffer, false);
		}
		else {
			next_object = create_operation_object(next_object, false);
			next_operator_priority= operator_priority(buffer, false);
		}
	}
	return std::make_shared<Operation_Object>(Operation_Object(object->get_position(), object, operator_token.get_type(), next_object));
}

// Atomic_Operative = Bracket | Single_Operative;
shared_ptr<Operative_Object> Parser::check_bracket_and_create_operative() {
	shared_ptr<Operative_Object> operative;
	if (is(Token::open_bracket)) {
		buffer = lexer.get_token();
		operative = create_operative_object();
		expect(Token::close_bracket, "Invalid Token, expected \')\'");
		buffer = lexer.get_token();
	}
	else {
		operative = create_single_operative_object();
	}
	return operative;
}

// Type_Variable_Declaration = Type, [”var”], Name, [Initialisation],{ Next_Variable },”;”;
shared_ptr<Declarations_Object> Parser::create_declarations_object() {
	std::vector<Variable_Object> variables;
	if (!buffer.is_variable_type()) {
		return nullptr;
	}
	Token type_token = buffer;
	do {
		auto variable = create_next_variable(type_token.get_type());
		variables.push_back(variable);
	} while (!is(Token::semicolon));
	
	return make_shared<Declarations_Object>(Declarations_Object(variables[0].get_position(),variables));
}

// Conditional_instruction = If_statement, { else(Scope | If_Statement) };
shared_ptr<Conditional_Object> Parser::create_conditional_object() {
	if (!is(Token::_if)) {
		return nullptr;
	}
	std::vector<If_Object>if_objects;
	auto if_token = buffer;
	bool else_after;
	do{
		else_after = false;
		if_objects.push_back(create_if_object());
		if (is(Token::_else)) {
			else_after=true;
			buffer = lexer.get_token();
		}
	} while (else_after && is(Token::_if));
	std::optional<Else_Object> else_object = {};
	if (else_after) {
		else_object= Else_Object(buffer.get_position());
		else_object->set_scope(create_scope());
	}
	return std::make_shared<Conditional_Object>(Conditional_Object(if_token.get_position(), if_objects, else_object));
}

// If_statement=”if”,”(”, Operative,”)”, Scope;
If_Object Parser::create_if_object() {
	auto if_token = buffer;
	buffer = lexer.get_token();
	expect(Token::open_bracket, "Invalid_Token");
	buffer = lexer.get_token();
	auto operative = create_operative_object();
	auto if_object = If_Object(if_token.get_position(), operative);
	expect(Token::close_bracket, "Invalid_Token");
	buffer = lexer.get_token();
	if_object.set_scope(create_scope());
	return if_object;
}

// Loop = ”while”, ”(”, Operative, ”)”, Scope;
shared_ptr<While_Object> Parser::create_while_object() {
	if (!is(Token::_while)) {
		return nullptr;
	}
	auto while_token = buffer;
	buffer = lexer.get_token();
	expect(Token::open_bracket);
	buffer = lexer.get_token();
	auto operative = create_operative_object();
	auto while_object = std::make_shared<While_Object>(While_Object(while_token.get_position(), operative));
	expect(Token::close_bracket);
	buffer = lexer.get_token();
	while_object->set_scope(create_scope());
	return while_object;
}

// Inspect = ”inspect”, ”(”, Operative, ”)”, ”{ ”,{Option},” }”;
shared_ptr<Inspect_Object> Parser::create_inspect_object() {
	if (!is(Token::inspect)) {
		return nullptr;
	}
	auto inspect_token = buffer;
	buffer = lexer.get_token();
	expect(Token::open_bracket, "Invalid_Token");
	buffer = lexer.get_token();
	auto operative = create_operative_object();
	buffer = lexer.get_token();
	expect(Token::open_buckle, "Invalid_Token");
	std::vector<std::shared_ptr<Inspect_Option_Object>> options;
	buffer = lexer.get_token();
	do{
		options.push_back(create_inspect_option_object(operative));
	} while (buffer.get_type() != Token::close_buckle);
	buffer = lexer.get_token();
	return std::make_shared<Inspect_Object>(Inspect_Object(inspect_token.get_position(),operative,options));
}

// Option = Inspect_Conditional, ”:”, Scope;
shared_ptr<Inspect_Option_Object> Parser::create_inspect_option_object(shared_ptr<Operative_Object> inspected) {
	auto conditional = create_inspect_conditional_object(inspected);
	buffer = lexer.get_token();
	expect(Token::colon, "Invalid Token");
	buffer = lexer.get_token();
	auto inspect_option_object = std::make_shared<Inspect_Option_Object>(Inspect_Option_Object(conditional->get_position(), conditional));
	inspect_option_object->set_scope(create_scope());
	return inspect_option_object;
}

// Inspect_Conditional = Is|As;
shared_ptr<Inspect_Conditional_Object> Parser::create_inspect_conditional_object(shared_ptr<Operative_Object> inspected){
	if (is(Token::name)) {
		return create_as_conditional_object(inspected);
	}
	if (is(Token::is)){
		return create_is_conditional_object();
	}
	raise_error(buffer.get_position(),"Invalid Token, expected name or is");
}

// As = (Name, ”as”, Type);
shared_ptr<As_Conditional_Object> Parser::create_as_conditional_object(shared_ptr<Operative_Object> inspected) {
	auto name_token = buffer;
	buffer = lexer.get_token();
	expect(Token::as, "Invalid_Token");
	buffer = lexer.get_token();
	if (!buffer.is_variable_type()) {
		raise_error(buffer.get_position(), "Invalid_Token");
	}
	return std::make_shared<As_Conditional_Object>(As_Conditional_Object(name_token.get_position(), std::get<std::string>(name_token.get_value()), buffer.get_type()));
}

// Is = ”is”, (”in”, Set | [operator], Constans | ”_”);
shared_ptr<Is_Conditional_Object> Parser::create_is_conditional_object() {
	auto is_token = buffer;
	buffer = lexer.get_token();
	shared_ptr<Inspect_Is_Conditional_Object> conditional;
	if (is(Token::in)) {
		auto in_token = buffer;
		auto set = create_set_object();
		conditional = std::make_shared<In_Conditional_Object>(In_Conditional_Object(in_token.get_position(), set));
	}
	else if (is(Token::name)) {
		if (std::get<std::string>(buffer.get_value()) != "_") {
			raise_error(buffer.get_position(), "Unexpected value, expected \"_\"");
		}
		conditional= std::make_shared<Default_Conditional_Object>(Default_Conditional_Object(buffer.get_position()));
	}
	else {
		Token::token_type _operator = Token::equal;
		if (buffer.is_operator_type()) {
			_operator = buffer.get_type();
			buffer = lexer.get_token();
		}
		auto constans = create_cosntans_object();
		conditional = std::make_shared<Compare_Conditional_Object>(Compare_Conditional_Object(buffer.get_position(),constans,_operator));
	}
	return std::make_shared<Is_Conditional_Object>(Is_Conditional_Object(is_token.get_position(),conditional));
}

// In_Set = operative, ”in”, Set;
shared_ptr<Operative_Object> Parser::create_in_set_object(shared_ptr<Operative_Object> object) {
	if (!is(Token::in)) {
		return nullptr;
	}
	auto set = create_set_object();
	buffer = lexer.get_token();
	return std::make_shared<In_Set_Object>(In_Set_Object(object->get_position(),object,set));
}

// Set = Zone | Collection
shared_ptr<Set_Object> Parser::create_set_object() {
	buffer = lexer.get_token();
	shared_ptr<Set_Object> set;
	set=create_zone_object();
	if (set) {
		return set;
	}
	set = create_colection_object();
	if (set) {
		return set;
	}
	raise_error(buffer.get_position(), "Invalid_token");
	return nullptr;
}

//Zone = ("(" | "["), Operative, Operative, (")" | "]");
shared_ptr<Zone_Object> Parser::create_zone_object() {
	bool left_closed=false;
	if (is(Token::open_square)) {
		left_closed = true;
	}
	else if (!is(Token::open_bracket)) {
		return nullptr;
	}
	buffer = lexer.get_token();
	auto left = create_operative_object();
	buffer = lexer.get_token();
	auto right = create_operative_object();
	bool right_closed=false;
	if (is(Token::close_square)) {
		right_closed = true;
	}
	else {
		expect(Token::close_bracket, "Invalid token");
	}
	return std::make_shared<Zone_Object>(Zone_Object(buffer.get_position(),left_closed,right_closed,left,right));
}

// Collection = "{",{Operative},"}";
shared_ptr<Colection_Object> Parser::create_colection_object() {
	if (!is(Token::open_buckle)) {
		return nullptr;
	}
	std::vector<std::shared_ptr<Operative_Object>> colection;
	while (!is(Token::close_buckle)) {
		buffer = lexer.get_token();
		colection.push_back(create_operative_object());
	}
	return std::make_shared<Colection_Object>(Colection_Object(buffer.get_position(),colection));
}

// Name_Started_Statement=[Call|Assign],";";
shared_ptr<Operative_Object> Parser::create_name_start_object() {
	if (buffer.get_type() != Token::name) {
		return nullptr;
	}
	auto name_token = buffer;
	buffer = lexer.get_token();
	auto function= create_function_call_object(name_token);
	if (function) {
		expect(Token::semicolon, "Invalid Token, expected \';\'");
		return function;
	}
	auto variable = create_variable_call_object(name_token);
	std::shared_ptr<Operative_Object> name_start_operative= variable;
	auto operative= create_operation_object(variable,true);
	if (operative) {
		name_start_operative = operative;
	}
	expect(Token::semicolon, "Invalid Token, expected \';\'");
	return name_start_operative;
}

// Return= ”return”, Log_Or;
shared_ptr<Return_Object> Parser::create_return_object() {
	if (!is(Token::_return)){
		return nullptr;
	}
	auto return_token = buffer;
	buffer = lexer.get_token();
	auto operative = create_operative_object();
	return std::make_shared<Return_Object>(Return_Object(return_token.get_position(), operative));
}

unsigned short operator_priority(Token operator_token, bool can_be_assign) {
	if (operator_token.get_type() == Token::multiplication || operator_token.get_type() == Token::division || operator_token.get_type() == Token::modulation) {
		return 1;
	}
	if (operator_token.get_type() == Token::summation || operator_token.get_type() == Token::subtraction) {
		return 2;
	}
	if (operator_token.get_type() == Token::shift_left || operator_token.get_type() == Token::shift_right) {
		return 3;
	}
	if (operator_token.get_type() == Token::less_or_equal || operator_token.get_type() == Token::grader_than || operator_token.get_type() == Token::grader_or_equal || operator_token.get_type() == Token::less_than) {
		return 4;
	}
	if (operator_token.get_type() == Token::equal || operator_token.get_type() == Token::not_equal) {
		return 5;
	}
	if (operator_token.get_type() == Token::bin_and) {
		return 6;
	}
	if (operator_token.get_type() == Token::bin_xor) {
		return 7;
	}
	if (operator_token.get_type() == Token::bin_or) {
		return 8;
	}
	if (operator_token.get_type() == Token::_and) {
		return 9;
	}
	if (operator_token.get_type() == Token::_or) {
		return 10;
	}
	if (operator_token.get_type() == Token::semicolon || operator_token.get_type() == Token::comma || operator_token.get_type() == Token::close_bracket || operator_token.get_type()==Token::in || operator_token.get_type() == Token::close_square || operator_token.get_type() == Token::close_buckle) {
		return 11;
	}
	if (can_be_assign && operator_token.get_type() == Token::assign) {
		return 11;
	}
	raise_error(operator_token.get_position(), "Invalid token, expected operator");
}

std::shared_ptr<Constans_Object>default_value(Token::token_type type) {
	value_variant value;
	if (type == Token::_char) {
		return std::make_shared<Char_Object>(Char_Object(Position(), '\0'));
	}
	else if (type == Token::_int) {
		return std::make_shared<Int_Object>(Int_Object(Position(), 0));
	}
	else if (type == Token::_float) {
		return std::make_shared<Float_Object>(Float_Object(Position(), 0.0));
	}
	return std::make_shared<String_Object>(String_Object(Position(), ""));
}