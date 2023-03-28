#include "../../../Validator/Validator.h"
#include "../../../Objects/Operatives/Constanses/Int_Object.h"
#include "../../../Objects/Operatives/Constanses/Float_Object.h"

int main() {
	In_Set_Object in_set(Position(), std::make_shared<Int_Object>(Position(), 1), std::make_shared<Zone_Object>(
		Position(),false,false,std::make_shared<Int_Object>(Position(), 0), std::make_shared<Int_Object>(Position(), 2)
		));
	Validator validator(true);
	in_set.accept(validator);
	auto code = in_set.generate_code();
	if (code == "In_Set (int 1 zone ( 0 2 ) ) ") {
		return 0; 
	}
	return -1;
}