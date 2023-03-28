#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"
#include "../../../Objects/Operatives/Constanses/String_Object.h"

int main() {
	Zone_Object zone(Position(), true, true,
		std::make_shared<Int_Object>(Position(), 0),
		std::make_shared<String_Object>(Position(), " "));
	Validator validator(true);
	try {
		zone.accept(validator);
	}
	catch (std::invalid_argument& e) {
		std::string error = e.what();
		if (error == "Error in File: main.apl Line: 1 Column: 0 Operative type and required type are not the same") {
			return 0;
		}
	}
	return -1;
}