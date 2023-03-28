#pragma once
#include <any>
#include <string>
#include <optional>
#include "../Objects/Dependent/Type_Object.h"

namespace As_Converters{
	using std::any, std::string, std::optional;
	any convert(any value,string current_type, string new_type);
	any convert(any value, Data_Type::type current_type, Data_Type::type new_type);
	// Wszystko musi zwracaæ any, inaczej w przypadku nieprawid³owej konwersji, zwróci niepusty any, a chodzi o to by by³ pusty 
	any char_to_float(any value);
	any char_to_int(any value);
	any char_to_string(any value);

	any float_to_char(any value);
	any float_to_int(any value);
	any float_to_string(any value);

	any int_to_char(any value);
	any int_to_float(any value);
	any int_to_string(any value);

	any string_to_char(any value);
	any string_to_float(any value);
	any string_to_int(any value);
}