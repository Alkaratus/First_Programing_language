#include "Located_Variable_Essence.h"

Located_Variable_Essence::Located_Variable_Essence(Variable_Object& variable):
	Variable_Essence(variable.get_essence()),
	file_name(variable.get_position().get_file().get_file_name())
{}

Located_Variable_Essence::Located_Variable_Essence(As_Conditional_Object & as_conditional):
	Variable_Essence(as_conditional.get_type(), as_conditional.get_name(), true),
	file_name(as_conditional.get_position().get_file().get_file_name())
{}

Located_Variable_Essence::Located_Variable_Essence(std::string _file_name, Variable_Essence essence):
	Variable_Essence(essence),
	file_name(_file_name)
{}

std::string Located_Variable_Essence::get_file_name(){
	return file_name;
}
