#include "Validated_Objects_Tree.h"

Validated_Object_Tree::Validated_Object_Tree(){}



bool Validated_Object_Tree::compare_arguments(std::vector <std::pair<Data_Type_Object, bool>> first, std::vector<Variable_Essence> second) {
	if (first.size() != second.size()) {
		return false;
	}
	int i = 0;
	while (i < first.size()) {
		if ((first[i].first.get_concrete() != second[i].get_type().get_concrete())) {
			return false;
		}
		i++;
	}
	return true;
}

bool Validated_Object_Tree::compare_arguments(std::vector <std::pair<Data_Type_Object, bool>> first, std::vector<Function_Argument> second) {
	if (first.size() != second.size()) {
		return false;
	}
	int i = 0;
	while (i < first.size()) {
		if ((first[i].first.get_concrete() != second[i].get_value()->get_type().get_concrete())) {
			return false;
		}
		if (!first[i].second && !second[i].is_copy() && !second[i].get_value()->is_l_value()) {
			raise_error(second[i].get_value()->get_position(), "Constans variable cannot be mutable argument");
		}
		i++;
	}
	return true;
}

int Validated_Object_Tree::is_in_variables(std::string name) {
	for (auto i = 0; i != variables.size(); i++) {
		if (variables[i].get_name() == name) {
			return i;
		}
	}
	return -1;
}

int Validated_Object_Tree::is_in_functions(std::string name) {
	for (auto i = 0; i != functions.size(); i++) {
		if (functions[i].get_name() == name) {
			return i;
		}
	}
	return -1;
}

int Validated_Object_Tree::is_in_functions(Function_Object new_function) {
	for (auto i = 0; i != functions.size(); i++) {
		if (functions[i].get_name() == new_function.get_name()) {
			if (compare_arguments(functions[i].get_arguments_essence(), new_function.get_arguments())) {
				return i;
			}
		}
	}
	return -1;
}

int Validated_Object_Tree::is_in_functions(Function_Call_Object function_call) {
	for (auto i = 0; i != functions.size(); i++) {
		if (functions[i].get_name() == function_call.get_name()) {
			if (compare_arguments(functions[i].get_arguments_essence(), function_call.get_arguments())) {
				return i;
			}
		}
	}
	return -1;
}

int Validated_Object_Tree::is_included(std::string name){
	for (auto i = 0; i != included_files.size(); i++) {
		if (name == included_files[i].first) {
			return i;
		}
	}
	return -1;
}

bool Validated_Object_Tree::is_lib_file(std::string name){
	auto found = is_included(name);
	return  (found == -1) ? false : included_files[found].second;
}

bool Validated_Object_Tree::is_alias_in_functions(std::string name){
	for (auto& function : functions) {
		if (function.get_alt_name() == name) {
			return true;
		}
	}
	return false;
}

void Validated_Object_Tree::add_variable(Variable_Object variable){
	variables.push_back(Located_Variable_Essence(variable));
}

void Validated_Object_Tree::add_variable(As_Conditional_Object as_conditional){
	variables.push_back(Located_Variable_Essence(as_conditional));
}

void Validated_Object_Tree::add_variable(Located_Variable_Essence located_essence){
	variables.push_back(located_essence);
}

void Validated_Object_Tree::add_function(Function_Object function, std::string alt_name){
	functions.push_back(Located_Function_Essence(function, alt_name));
}

void Validated_Object_Tree::add_included(std::string name, bool is_library){
	included_files.push_back({ name,is_library });
}

Located_Variable_Essence Validated_Object_Tree::get_variable(int index) const {
	return variables[index];
}

Located_Function_Essence Validated_Object_Tree::get_function(int index) const {
	return functions[index];
}

Located_Function_Essence Validated_Object_Tree::get_last_function() const {
	return functions.back();
}

std::vector<Located_Variable_Essence> Validated_Object_Tree::get_variables() const{
	return variables;
}

std::vector<Located_Function_Essence> Validated_Object_Tree::get_functions() const{
	return functions;
}

void Validated_Object_Tree::operator+=(Validated_Object_Tree other){
	add_objects(other.get_objects());
	variables.insert(variables.end(), other.variables.begin(), other.variables.end());
	auto new_functions = other.functions;
	functions.insert(functions.end(), new_functions.begin(), new_functions.end());
}

Validated_Object_Tree Validated_Object_Tree::get_tree_without_objects() const{
	Validated_Object_Tree new_tree;
	new_tree.included_files = included_files;
	new_tree.variables = variables;
	new_tree.functions = functions;
	return new_tree;
}
