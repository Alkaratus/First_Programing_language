#include "Operations.h"
#include <cmath>

using std::shared_ptr, std::make_shared, std::string;

shared_ptr<char>Operations::_and(shared_ptr<char>first_value, shared_ptr<char>second_value) {
	return make_shared<char>(*first_value.get() && *second_value.get());
}

shared_ptr<char> Operations::_or(shared_ptr<char>first_value, shared_ptr<char>second_value) {
	return make_shared<char>(*first_value.get() || *second_value.get());
}

shared_ptr<double>Operations::double_modulo(shared_ptr<double>first_value, shared_ptr<double>second_value) {
	auto whole = floor(*first_value.get()/(*second_value.get()));
	return make_shared<double>(*first_value.get() - whole * (*second_value.get()));
}

shared_ptr<char>Operations::chars_operations(shared_ptr<char>first_value, shared_ptr<char>second_value, string _operator) {
	if (_operator == "+") {
		return summation<char>(first_value, second_value);
	}
	if (_operator == "-") {
		return subtraction<char>(first_value, second_value);
	}
	if (_operator == "*") {
		return multiplication<char>(first_value, second_value);
	}
	if (_operator == "/") {
		return division<char>(first_value, second_value);
	}
	if (_operator == "%") {
		return modulation<char>(first_value, second_value);
	}
	if (_operator == "&") {
		return bin_and<char>(first_value, second_value);
	}
	if (_operator == "|") {
		return bin_or<char>(first_value, second_value);
	}
	if (_operator == "^") {
		return bin_xor<char>(first_value, second_value);
	}
	if (_operator == "<<") {
		return shift_left<char>(first_value, second_value);
	}
	if (_operator == ">>") {
		return shift_right<char>(first_value, second_value);
	}
	if (_operator == "&&") {
		return _and(first_value, second_value);
	}
	if (_operator == ">>") {
		return _or(first_value, second_value);
	}
}

shared_ptr<double>Operations::floats_operations(shared_ptr<double>first_value, shared_ptr<double>second_value, string _operator) {
	if (_operator == "+") {
		return summation<double>(first_value, second_value);
	}
	if (_operator == "-") {
		return subtraction<double>(first_value, second_value);
	}
	if (_operator == "*") {
		return multiplication<double>(first_value, second_value);
	}
	if (_operator == "/") {
		return division<double>(first_value, second_value);
	}
	if (_operator == "%") {
		return double_modulo(first_value, second_value);
	}
}

shared_ptr<long long int>Operations::ints_operations(shared_ptr<long long int>first_value, shared_ptr<long long int>second_value, string _operator) {
	if (_operator == "+") {
		return summation<long long int>(first_value, second_value);
	}
	if (_operator == "-") {
		return subtraction<long long int>(first_value, second_value);
	}
	if (_operator == "*") {
		return multiplication<long long int>(first_value, second_value);
	}
	if (_operator == "/") {
		return division<long long int>(first_value, second_value);
	}
	if (_operator == "%") {
		return modulation<long long int>(first_value, second_value);
	}
	if (_operator == "&") {
		return bin_and<long long int>(first_value, second_value);
	}
	if (_operator == "|") {
		return bin_or<long long int>(first_value, second_value);
	}
	if (_operator == "^") {
		return bin_xor<long long int>(first_value, second_value);
	}
	if (_operator == "<<") {
		return shift_left<long long int>(first_value, second_value);
	}
	if (_operator == ">>") {
		return shift_right<long long int>(first_value, second_value);
	}
}

shared_ptr<string>Operations::strings_operations(shared_ptr<string>first_value, shared_ptr<string>second_value, string _operator) {
	if (_operator == "+") {
		return summation<string>(first_value, second_value);
	}
}
