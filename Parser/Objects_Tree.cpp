#include "Objects_Tree.h"


Object_Tree::Object_Tree(compilation_objects_ptrs_list _objects):
	objects(_objects)
{}

void Object_Tree::add_object(std::shared_ptr<Compilation_Object> object) {
	objects.push_back(object);
}

void Object_Tree::add_objects(compilation_objects_ptrs_list other_objects){
	objects.insert(objects.end(), other_objects.begin(), other_objects.end());
}

compilation_objects_ptrs_list Object_Tree::get_objects() {
	return objects;
}

std::string Object_Tree::generate_code() {
	std::string code;
	for (auto object : objects) {
		code += object->generate_code();
	}
	return code;
}