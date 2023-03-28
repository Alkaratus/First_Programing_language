#pragma once
#include <vector>
#include "Located_Variable_Essence.h"
#include "Located_Function_Essence.h"
#include "../Parser/Objects_Tree.h"
#include "../Objects/Operatives/Function_Call_Object.h"


class Validated_Object_Tree :public Object_Tree {
	std::vector<std::pair<std::string,bool>>included_files;
	std::vector<Located_Variable_Essence> variables;
	std::vector<Located_Function_Essence> functions;

	bool compare_arguments(std::vector <std::pair<Data_Type_Object, bool>> first, std::vector<Variable_Essence> second);
	bool compare_arguments(std::vector <std::pair<Data_Type_Object, bool>> first, std::vector<Function_Argument> second);
	
public:
	Validated_Object_Tree();

	int is_in_variables(std::string name);
	int is_in_functions(std::string name);
	int is_in_functions(Function_Object new_function);
	int is_in_functions(Function_Call_Object function_call);
	int is_included(std::string name);

	bool is_lib_file(std::string name);
	bool is_alias_in_functions(std::string name);

	void add_variable(Variable_Object variable);
	void add_variable(As_Conditional_Object as_conditional);
	void add_variable(Located_Variable_Essence located_essence);
	void add_function(Function_Object function, std::string alt_name);
	void add_included(std::string name, bool is_library);

	Located_Variable_Essence get_variable(int index) const;
	Located_Function_Essence get_function(int index) const;
	Located_Function_Essence get_last_function() const;

	std::vector<Located_Variable_Essence> get_variables() const;
	std::vector<Located_Function_Essence> get_functions() const;

	void operator+=(Validated_Object_Tree other);
	Validated_Object_Tree get_tree_without_objects() const;
};