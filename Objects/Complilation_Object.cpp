#include "Complilation_Object.h"

Compilation_Object::Compilation_Object(Position _position):position(_position){}

Position Compilation_Object::get_position() {
	return position;
}