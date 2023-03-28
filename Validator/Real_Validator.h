#pragma once
#include "Validator.h"

class Real_Validator : private Validator {
	Object_Tree& tree;
	Real_Validator(Object_Tree& _tree);
	Validated_Object_Tree validate();
};