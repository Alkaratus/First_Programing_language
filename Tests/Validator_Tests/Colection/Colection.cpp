#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"

int main() {
	Colection_Object colection(Position(), {
		std::make_shared<Int_Object>(Position(),1),
		std::make_shared<Int_Object>(Position(),2),
		std::make_shared<Int_Object>(Position(),3)
	});
	Validator validator(true);
	colection.accept(validator);
	auto code= colection.generate_code();
	if (code == "colection { 1 2 3 } ") {
		return 0; 
	}
	return -1;
}