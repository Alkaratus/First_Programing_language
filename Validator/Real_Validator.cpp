#include "Real_Validator.h"

Real_Validator::Real_Validator(Object_Tree& _tree):
	Validator(true),tree(_tree)
{}


Validated_Object_Tree Real_Validator::validate() {
	auto validated_tree=validate_tree(tree);
	if (validated_tree.is_in_functions("main") == -1) {
		raise_error(Position(), "Function main was not found");
	}
	return validated_tree;
}
