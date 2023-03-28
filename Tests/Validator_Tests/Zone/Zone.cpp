#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"
#include "../../../Objects/Operatives/Constanses/Float_Object.h"

int main() {
	Zone_Object zone(Position(), true, true, 
		std::make_shared<Int_Object>(Position(), 0),
		std::make_shared<Int_Object>(Position(), 2));
	Validator validator(true);
	zone.accept(validator);
	auto code= zone.generate_code();
	if (code == "zone [ 0 2 ] ") {
		return 0; 
	}
	return -1;
}