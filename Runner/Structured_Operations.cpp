#include "Structured_Operations.h"

using std::make_shared;

shared_ptr<double>double_modulo(shared_ptr<double>first_value, shared_ptr<double>second_value) {
	auto whole = floor(*first_value.get() / (*second_value.get()));
	return make_shared<double>(*first_value.get() - whole * (*second_value.get()));
}

value Assign::operator()(shared_ptr<char> first, shared_ptr<char> second){
	*first.get() = *second.get();
	return shared_ptr<char>(0);
}

value Assign::operator()(shared_ptr<double> first, shared_ptr<double> second){
	*first.get() = *second.get();
	return shared_ptr<char>(0);
}

value Assign::operator()(shared_ptr<long long int> first, shared_ptr<long long int> second) {
	*first.get() = *second.get();
	return shared_ptr<char>(0);
}

value Assign::operator()(shared_ptr<string> first, shared_ptr<string> second) {
	*first.get() = *second.get();
	return shared_ptr<char>(0);
}

value Equal::operator()(shared_ptr<char> first, shared_ptr<char> second){
	return make_shared<char>(*first.get() == *second.get());
}

value Equal::operator()(shared_ptr<double> first, shared_ptr<double> second) {
	return make_shared<char>(*first.get() == *second.get());
}

value Equal::operator()(shared_ptr<long long int> first, shared_ptr<long long int> second) {
	return make_shared<char>(*first.get() == *second.get());
}

value Equal::operator()(shared_ptr<string> first, shared_ptr<string> second) {
	return make_shared<char>(*first.get() == *second.get());
}

value Not_Equal::operator()(shared_ptr<char> first, shared_ptr<char> second){
	return make_shared<char>(*first.get() != *second.get());
}

value Not_Equal::operator()(shared_ptr<double> first, shared_ptr<double> second) {
	return make_shared<char>(*first.get() != *second.get());
}

value Not_Equal::operator()(shared_ptr<long long int> first, shared_ptr<long long int> second) {
	return make_shared<char>(*first.get() != *second.get());
}

value Not_Equal::operator()(shared_ptr<string> first, shared_ptr<string> second) {
	return make_shared<char>(*first.get() != *second.get());
}

value Grader_Or_Equal::operator()(shared_ptr<char> first, shared_ptr<char> second){
	return make_shared<char>(*first.get() >= *second.get());
}

value Grader_Or_Equal::operator()(shared_ptr<double> first, shared_ptr<double> second) {
	return make_shared<char>(*first.get() >= *second.get());
}

value Grader_Or_Equal::operator()(shared_ptr<long long int> first, shared_ptr<long long int> second) {
	return make_shared<char>(*first.get() >= *second.get());
}

value Grader_Or_Equal::operator()(shared_ptr<string> first, shared_ptr<string> second) {
	return make_shared<char>(*first.get() >= *second.get());
}

value Grader_Than::operator()(shared_ptr<char> first, shared_ptr<char> second){
	return make_shared<char>(*first.get() > *second.get());
}

value Grader_Than::operator()(shared_ptr<double> first, shared_ptr<double> second) {
	return make_shared<char>(*first.get() > *second.get());
}

value Grader_Than::operator()(shared_ptr<long long int> first, shared_ptr<long long int> second) {
	return make_shared<char>(*first.get() > *second.get());
}

value Grader_Than::operator()(shared_ptr<string> first, shared_ptr<string> second) {
	return make_shared<char>(*first.get() > *second.get());
}

value Less_Or_Equal::operator()(shared_ptr<char> first, shared_ptr<char> second) {
	return make_shared<char>(*first.get() <= *second.get());
}

value Less_Or_Equal::operator()(shared_ptr<double> first, shared_ptr<double> second) {
	return make_shared<char>(*first.get() <= *second.get());
}

value Less_Or_Equal::operator()(shared_ptr<long long int> first, shared_ptr<long long int> second) {
	return make_shared<char>(*first.get() <= *second.get());
}

value Less_Or_Equal::operator()(shared_ptr<string> first, shared_ptr<string> second) {
	return make_shared<char>(*first.get() <= *second.get());
}

value Less_Than::operator()(shared_ptr<char> first, shared_ptr<char> second){
	return make_shared<char>(*first.get() < *second.get());
}

value Less_Than::operator()(shared_ptr<double> first, shared_ptr<double> second) {
	return make_shared<char>(*first.get() < *second.get());
}

value Less_Than::operator()(shared_ptr<long long int> first, shared_ptr<long long int> second) {
	return make_shared<char>(*first.get() < *second.get());
}

value Less_Than::operator()(shared_ptr<string> first, shared_ptr<string> second) {
	return make_shared<char>(*first.get() < *second.get());
}

value Summation::operator()(shared_ptr<char> first, shared_ptr<char> second) {
	return make_shared<char>(*first.get() + *second.get());
}

value Summation::operator()(shared_ptr<double> first, shared_ptr<double> second) {
	return make_shared<double>(*first.get() + *second.get());
}

value Summation::operator()(shared_ptr<long long int> first, shared_ptr<long long int> second) {
	return make_shared<long long int>(*first.get() + *second.get());
}

value Summation::operator()(shared_ptr<string> first, shared_ptr<string> second) {
	return make_shared<string>(*first.get() + *second.get());
}

value Division::operator()(shared_ptr<char> first, shared_ptr<char> second){
	if (*second.get() == 0) {
		throw std::invalid_argument("Zero division error");
	}
	return make_shared<char>(*first.get() / *second.get());
}

value Division::operator()(shared_ptr<double> first, shared_ptr<double> second) {
	if (*second.get() == 0) {
		throw std::invalid_argument("Zero division error");
	}
	return make_shared<double>(*first.get() / *second.get());
}

value Division::operator()(shared_ptr<long long int> first, shared_ptr<long long int> second) {
	if (*second.get() == 0) {
		throw std::invalid_argument("Zero division error");
	}
	return make_shared<long long int>(*first.get() / *second.get());
}

value Modulation::operator()(shared_ptr<char> first, shared_ptr<char> second) {
	return make_shared<char>(*first.get() % *second.get());
}

value Modulation::operator()(shared_ptr<double> first, shared_ptr<double> second) {
	return double_modulo(first,second);
}

value Modulation::operator()(shared_ptr<long long int> first, shared_ptr<long long int> second) {
	return make_shared<long long int>(*first.get() % *second.get());
}

value Multiplication::operator()(shared_ptr<char> first, shared_ptr<char> second) {
	return make_shared<char>(*first.get() * *second.get());
}

value Multiplication::operator()(shared_ptr<double> first, shared_ptr<double> second) {
	return make_shared<double>(*first.get() * *second.get());
}

value Multiplication::operator()(shared_ptr<long long int> first, shared_ptr<long long int> second) {
	return make_shared<long long int>(*first.get() * *second.get());
}

value Subtraction::operator()(shared_ptr<char> first, shared_ptr<char> second) {
	return make_shared<char>(*first.get() - *second.get());
}

value Subtraction::operator()(shared_ptr<double> first, shared_ptr<double> second) {
	return make_shared<double>(*first.get() - *second.get());
}

value Subtraction::operator()(shared_ptr<long long int> first, shared_ptr<long long int> second) {
	return make_shared<long long int>(*first.get() - *second.get());
}

value Bin_And::operator()(shared_ptr<char> first, shared_ptr<char> second) {
	return make_shared<char>(*first.get() & *second.get());
}

value Bin_And::operator()(shared_ptr<long long int> first, shared_ptr<long long int> second) {
	return make_shared<long long int>(*first.get() & *second.get());
}

value Bin_Or::operator()(shared_ptr<char> first, shared_ptr<char> second) {
	return make_shared<char>(*first.get() | *second.get());
}

value Bin_Or::operator()(shared_ptr<long long int> first, shared_ptr<long long int> second) {
	return make_shared<long long int>(*first.get() | *second.get());
}

value Bin_Xor::operator()(shared_ptr<char> first, shared_ptr<char> second) {
	return make_shared<char>(*first.get() ^ *second.get());
}

value Bin_Xor::operator()(shared_ptr<long long int> first, shared_ptr<long long int> second) {
	return make_shared<long long int>(*first.get() ^ *second.get());
}

value Shift_Left::operator()(shared_ptr<char> first, shared_ptr<char> second) {
	return make_shared<char>(*first.get() << *second.get());
}

value Shift_Left::operator()(shared_ptr<long long int> first, shared_ptr<long long int> second) {
	return make_shared<long long int>(*first.get() << *second.get());
}

value Shift_Right::operator()(shared_ptr<char> first, shared_ptr<char> second) {
	return make_shared<char>(*first.get() >> *second.get());
}

value Shift_Right::operator()(shared_ptr<long long int> first, shared_ptr<long long int> second) {
	return make_shared<long long int>(*first.get() >> *second.get());
}

value _Or::operator()(shared_ptr<char> first, shared_ptr<char> second){
	return make_shared<char>(*first.get() || *second.get());
}

value _And::operator()(shared_ptr<char> first, shared_ptr<char> second){
	return make_shared<char>(*first.get() && *second.get());
}
