#pragma once
#include "../Operative_Object.h"

class Constans_Object :public Operative_Object {
public:
	Constans_Object(Position position, Data_Type_Object _data_type);
	virtual ~Constans_Object() = default;
	
	virtual value_variant get_value()=0;
};