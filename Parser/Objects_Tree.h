#pragma once
#include <vector>
#include <memory>
#include "../Objects/Complilation_Object.h"
#include "../Overall/Compile_message.h"

typedef std::vector<std::shared_ptr<Compilation_Object>> compilation_objects_ptrs_list;

class Object_Tree {
	compilation_objects_ptrs_list objects;
public:
	Object_Tree(compilation_objects_ptrs_list _objects= compilation_objects_ptrs_list());
	void add_object(std::shared_ptr<Compilation_Object> object);
	void add_objects(compilation_objects_ptrs_list other_objects);
	compilation_objects_ptrs_list get_objects();
	std::string generate_code();
};