#include "../Visitor/Visitor.h"
#include <variant>
#include <map>
#include <string>
#include "../Validator/Validated_Objects_Tree.h"
#include <optional>
#include "Structured_Operations.h"

using std::shared_ptr, std::string;

class Executor :public Visitor {
	//Pre execution
	unsigned long long int main_index;
	bool preparation;

	
	Validated_Object_Tree tree;
	std::map<string, value> global_vars,vars;
	std::map<string, unsigned long long int>function_indexes;

	value operation_register, return_register, inspect_register;
	Data_Type::type inspected_type;
	string as_variable_name;
	bool scope_executed, condition_flag,return_called;
	
	std::vector<Function_Argument>function_arguments;
	std::vector<string> scope_variables;
	
	void create_variable_value(shared_ptr<Operative_Object> value);
	void execute_operation(value first, value second, Operator_Type::type type);
	void execute_lib_function(Function_Call_Object& function_call);
	bool check_condition(Data_Type::type type);
	value create_copy(Data_Type::type type);
	value return_default(Data_Type::type type);
public:
	Executor(Validated_Object_Tree tree=Validated_Object_Tree());
	void visit(Conditional_Object& conditional) override;
	void visit(Declarations_Object& declarations) override;
	void visit(Include_Object& include) override {}
	void visit(Inspect_Object& inspect) override;
	void visit(Return_Object& _return) override;
	void visit(Variable_Object& variable) override;

	void visit(Scope_Object& scope) override;

	void visit(Is_Conditional_Object& is_conditional) override;
	void visit(Compare_Conditional_Object& compare_conditional) override;
	void visit(Default_Conditional_Object& default_conditional) override;
	void visit(In_Conditional_Object& in_conditional) override;
	void visit(As_Conditional_Object& as_conditional) override;

	void visit(Variable_Call_Object& variable_call)override;
	void visit(Function_Call_Object& function_call)override;
	void visit(Operation_Object& operation)override;
	void visit(In_Set_Object& in_set)override;

	void visit(Char_Object& _char) override;
	void visit(Float_Object& in_set) override;
	void visit(Int_Object& in_set) override;
	void visit(String_Object& in_set) override;

	void visit(Function_Object& function) override;
	void visit(If_Object& _if)override;
	void visit(Else_Object& _else)override;
	void visit(Inspect_Option_Object& inspect_option_object)override;
	void visit(While_Object& _while)override;

	void visit(Colection_Object& collection) override;
	void visit(Zone_Object& zone) override;

	void prepere_to_execute();
	void execute();

	value get_var(string name);
	value get_register();
	value get_return_register();
};