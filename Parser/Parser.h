#pragma once
#include <vector>
#include <memory>

#include "../Source/Source.h"

#include "../Lexer/Lexer.h"
#include "../Lexer/Source_Lexer.h"
#include "../Lexer/Token_Collection.h"

#include "../Objects/Complilation_Object.h"
#include "../Objects/Include_Object.h"
#include "../Objects/Inspect_Object.h"
#include "../Objects/Conditional_Object.h"
#include "../Objects/Declarations_Object.h"
#include "../Objects/Return_Object.h"

#include "../Objects/Operatives/Variable_Call_Object.h"
#include "../Objects/Operatives/Function_Call_Object.h"
#include "../Objects/Operatives/Operation_Object.h"

#include "../Objects/Operatives/Constanses/String_Object.h"
#include "../Objects/Operatives/Constanses/Int_Object.h"
#include "../Objects/Operatives/Constanses/Float_Object.h"
#include "../Objects/Operatives/Constanses/Char_Object.h"

#include "../Objects/Scopeds/Function_Object.h"
#include "../Objects/Scopeds/If_Object.h"
#include "../Objects/Scopeds/While_Object.h"
#include "../Objects/Scopeds/Inspect_Option_Object.h"

#include "../Objects/Sets/Zone_Object.h"
#include "../Objects/Sets/Colection_Object.h"

#include "../Objects/Inspect_Conditionals/Inspect_Conditional_Object.h"
#include "../Objects/Inspect_Conditionals/As_Conditional_Object.h"
#include "../Objects/Inspect_Conditionals/Is_Conditional_Object.h"


using std::shared_ptr;
using std::vector;

class Parser {
	Lexer &lexer;
	Token buffer;
public:
	bool is(Token::token_type) const;
	void expect(Token::token_type expected, std::string message_if_invalid="Invalid token");
	void expect(std::vector<Token::token_type> const, std::string message_if_invalid = "Invalid token");
	void expect(bool (Token::* method)()  const, std::string message_if_invalid = "Invalid token");
	bool consume_if(Token::token_type possible);
	bool is_lexer_end();

	Scope_Object create_scope();
	
	shared_ptr<Include_Object> create_include_object();
	shared_ptr<Function_Object> create_void_function();
	shared_ptr<Variable_Object> create_auto_variable_object();
	shared_ptr<Compilation_Object> create_type_start_object();
	shared_ptr<Declarations_Object> create_variable_begin_declarations_object(Token::token_type type);
	shared_ptr<Function_Object> create_function_object(Token::token_type type, Token name);
	shared_ptr<Declarations_Object> create_constans_begin_declarations_object(Token::token_type type, Token name);
	Variable_Object create_next_variable(Token::token_type type);
	vector<Variable_Essence> create_list_of_arguments();

	shared_ptr<Operative_Object> create_operative_object();
	shared_ptr<Operative_Object> create_operation_object(shared_ptr<Operative_Object> object, bool can_be_assign);
	shared_ptr<Operative_Object> create_single_operative_object();
	shared_ptr<Constans_Object> create_cosntans_object();
	shared_ptr<String_Object> create_string_object();
	shared_ptr<Char_Object> create_char_object();
	shared_ptr<Constans_Object> create_numeric_object();
	shared_ptr<Float_Object> create_float_object(bool minus);
	shared_ptr<Int_Object> create_int_object(bool minus);
	shared_ptr<Operative_Object> create_call_object();
	shared_ptr<Variable_Call_Object> create_variable_call_object(Token name);
	shared_ptr<Function_Call_Object> create_function_call_object(Token name);
	shared_ptr<Operative_Object> check_bracket_and_create_operative();

	shared_ptr<Declarations_Object> create_declarations_object();
	shared_ptr<Conditional_Object> create_conditional_object();
	If_Object create_if_object();
	shared_ptr<While_Object> create_while_object();

	shared_ptr<Inspect_Object> create_inspect_object();
	shared_ptr<Inspect_Option_Object> create_inspect_option_object(shared_ptr<Operative_Object> inspected);
	shared_ptr<Inspect_Conditional_Object>create_inspect_conditional_object(shared_ptr<Operative_Object> inspected);
	shared_ptr<As_Conditional_Object>create_as_conditional_object(shared_ptr<Operative_Object> inspected);
	shared_ptr<Is_Conditional_Object>create_is_conditional_object();

	shared_ptr<Operative_Object> create_in_set_object(shared_ptr<Operative_Object> object);
	shared_ptr<Set_Object> create_set_object();
	shared_ptr<Zone_Object> create_zone_object();
	shared_ptr<Colection_Object> create_colection_object();

	shared_ptr<Operative_Object>create_name_start_object();
	shared_ptr<Return_Object>create_return_object();
		

	Parser(Lexer &lexer);
	shared_ptr<Compilation_Object> parse();
	shared_ptr<Compilation_Object> parse_in_scope();
};

unsigned short operator_priority(Token operator_token, bool can_be_assign);
std::shared_ptr<Constans_Object>default_value(Token::token_type token);