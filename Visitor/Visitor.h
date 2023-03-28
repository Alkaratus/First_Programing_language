#pragma once
#include "../Objects/Conditional_Object.h"
#include "../Objects/Declarations_Object.h"
#include "../Objects/Include_Object.h"
#include "../Objects/Inspect_Object.h"
#include "../Objects/Return_Object.h"
#include "../Objects/Variable_Object.h"

#include "../Objects/Inspect_Conditionals/Is_Conditional_Object.h"
#include "../Objects/Inspect_Conditionals/Inspect_Is_Conditionals/Compare_Conditional_Object.h"
#include "../Objects/Inspect_Conditionals/Inspect_Is_Conditionals/Default_Conditional_Object.h"
#include "../Objects/Inspect_Conditionals/Inspect_Is_Conditionals/In_Conditional_Object.h"
#include "../Objects/Inspect_Conditionals/As_Conditional_Object.h"

#include "../Objects/Scopeds/Function_Object.h"
#include "../Objects/Scopeds/If_Object.h"
#include "../Objects/Scopeds/Else_Object.h"
#include "../Objects/Scopeds/Inspect_Option_Object.h"
#include "../Objects/Scopeds/While_Object.h"

#include "../Objects/Operatives/Variable_Call_Object.h"
#include "../Objects/Operatives/Function_Call_Object.h"
#include "../Objects/Operatives/Operation_Object.h"
#include "../Objects/Operatives/In_Set_Object.h"

#include "../Objects/Operatives/Constanses/Char_Object.h"
#include "../Objects/Operatives/Constanses/Float_Object.h"
#include "../Objects/Operatives/Constanses/Int_Object.h"
#include "../Objects/Operatives/Constanses/String_Object.h"

#include "../Objects/Sets/Colection_Object.h"
#include "../Objects/Sets/Zone_Object.h"

class Visitor {
public:
	virtual ~Visitor() = default;

	virtual void visit(Conditional_Object& conditional) = 0;
	virtual void visit(Declarations_Object& declarations) = 0;
	virtual void visit(Include_Object& include) = 0;
	virtual void visit(Inspect_Object& inspect) = 0;
	virtual void visit(Return_Object& _return) = 0;
	virtual void visit(Variable_Object& variable) = 0;

	virtual void visit(Scope_Object& scope) = 0;

	virtual void visit(Is_Conditional_Object& is_conditional) = 0;
	virtual void visit(Compare_Conditional_Object& compare_conditional) = 0;
	virtual void visit(Default_Conditional_Object& default_conditional) = 0;
	virtual void visit(In_Conditional_Object& in_conditional) = 0;
	virtual void visit(As_Conditional_Object& as_conditional) = 0;

	virtual void visit(Variable_Call_Object& variable_call) = 0;
	virtual void visit(Function_Call_Object& function_call) = 0;
	virtual void visit(Operation_Object& operation) = 0;
	virtual void visit(In_Set_Object& in_set) = 0;

	virtual void visit(Char_Object& in_set) = 0;
	virtual void visit(Float_Object& in_set) = 0;
	virtual void visit(Int_Object& in_set) = 0;
	virtual void visit(String_Object& in_set) = 0;
	
	virtual void visit(Function_Object& function) = 0;
	virtual void visit(If_Object& _if) = 0;
	virtual void visit(Else_Object& _else) = 0;
	virtual void visit(Inspect_Option_Object& inspect_option_object) = 0;
	virtual void visit(While_Object& _while) = 0;

	virtual void visit(Colection_Object& collection)=0;
	virtual void visit(Zone_Object& zone)=0;
	
};