#pragma once
#include <list>
#include <memory>
#include "../Source/Source_File.h"
#include "../Visitor/Visitor.h"
#include "Validated_Objects_Tree.h"


class Validator:public Visitor {
	Validated_Object_Tree validated_tree;
	bool test, was_include, is_lib_file;
	void manage_included_file(std::shared_ptr<Source_File>source);
	void validate_and_check_type(std::shared_ptr<Operative_Object>& operative, Data_Type::type expected_type);
	std::string create_alias(std::string function_name);
public:
	Validator(bool _test=false);
	Validator(Validator const& other);
	
	void visit(Conditional_Object& conditional) override;
	void visit(Declarations_Object& declarations) override;
	void visit(Include_Object& include) override;
	void visit(Inspect_Object& inspect) override;
	void visit(Return_Object& _return) override;
	void visit(Variable_Object &variable) override;

	void visit(Scope_Object& scope) override;

	void visit(Is_Conditional_Object& is_conditional) override;
	void visit(Compare_Conditional_Object& compare_conditional) override;
	void visit(Default_Conditional_Object& default_conditional) override{}
	void visit(In_Conditional_Object& in_conditional) override;
	void visit(As_Conditional_Object& as_conditional) override;

	void visit(Variable_Call_Object &variable_call)override;
	void visit(Function_Call_Object &function_call)override;
	void visit(Operation_Object &operation)override;
	void visit(In_Set_Object& in_set)override;

	void visit(Char_Object& in_set) override{}
	void visit(Float_Object& in_set) override{}
	void visit(Int_Object& in_set) override{}
	void visit(String_Object& in_set) override{}
	
	void visit(Function_Object& function) override;
	void visit(If_Object& _if)override;
	void visit(Else_Object& _else)override;
	void visit(Inspect_Option_Object& inspect_option_object)override;
	void visit(While_Object& _while)override;

	void visit(Colection_Object& collection) override;
	void visit(Zone_Object& zone) override;

	Validated_Object_Tree get_current_tree();
	Validated_Object_Tree validate_tree(Object_Tree tree);
};

std::shared_ptr<Source_File> try_open_file(std::string file_name);
bool is_possible_operation(Data_Type::type data_type, Operator_Type::type operator_type);
Data_Type::type set_operation_result_type(Data_Type::type data_type, Operator_Type::type operator_type);