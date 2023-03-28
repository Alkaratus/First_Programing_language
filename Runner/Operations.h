#pragma once
#include <string>
#include <memory>

namespace Operations {
	using std::shared_ptr, std::make_shared, std::string;

	template <typename T>shared_ptr<void>assign(shared_ptr<T>where, shared_ptr<T>what) {
		*where.get() = *what.get();
		return nullptr;
	}

	template <typename T>shared_ptr<char>equal(shared_ptr<T>first_value, shared_ptr<T>second_value) {
		return make_shared<char>(*first_value.get() == *second_value.get());
	}

	template <typename T>shared_ptr<char>grader_or_equal(shared_ptr<T>first_value, shared_ptr<T>second_value) {
		return make_shared<char>(*first_value.get() >= *second_value.get());
	}

	template <typename T>shared_ptr<char>grader_than(shared_ptr<T>first_value, shared_ptr<T>second_value) {
		return make_shared<char>(*first_value.get() > *second_value.get());
	}

	template <typename T>shared_ptr<char>less_or_equal(shared_ptr<T>first_value, shared_ptr<T>second_value) {
		return make_shared<char>(*first_value.get() <= *second_value.get());
	}

	template <typename T>shared_ptr<char>less_than(shared_ptr<T>first_value, shared_ptr<T>second_value) {
		return make_shared<char>(*first_value.get() < *second_value.get());
	}

	template <typename T>shared_ptr<char>not_equal(shared_ptr<T>first_value, shared_ptr<T>second_value) {
		return make_shared<char>(*first_value.get() != *second_value.get());
	}

	template <typename T>shared_ptr<T>summation(shared_ptr<T>first_value, shared_ptr<T>second_value) {
		return make_shared<T>(*first_value.get() + *second_value.get());
	}

	template <typename T>shared_ptr<T>division(shared_ptr<T>first_value, shared_ptr<T>second_value) {
		return make_shared<T>(*first_value.get() / *second_value.get());
	}

	template <typename T>shared_ptr<T>modulation(shared_ptr<T>first_value, shared_ptr<T>second_value) {
		return make_shared<T>(*first_value.get() % *second_value.get());
	}

	template <typename T>shared_ptr<T>multiplication(shared_ptr<T>first_value, shared_ptr<T>second_value) {
		return make_shared<T>(*first_value.get() * *second_value.get());
	}

	template <typename T>shared_ptr<T>subtraction(shared_ptr<T>first_value, shared_ptr<T>second_value) {
		return make_shared<T>(*first_value.get() - *second_value.get());
	}

	template <typename T>shared_ptr<T>bin_and(shared_ptr<T>first_value, shared_ptr<T>second_value) {
		return make_shared<T>(*first_value.get() * *second_value.get());
	}

	template <typename T>shared_ptr<T>bin_or(shared_ptr<T>first_value, shared_ptr<T>second_value) {
		return make_shared<T>(*first_value.get() | *second_value.get());
	}

	template <typename T>shared_ptr<T>bin_xor(shared_ptr<T>first_value, shared_ptr<T>second_value) {
		return make_shared<T>(*first_value.get() ^ *second_value.get());
	}

	template <typename T>shared_ptr<T>shift_left(shared_ptr<T>first_value, shared_ptr<T>second_value) {
		return make_shared<T>(*first_value.get() << *second_value.get());
	}

	template <typename T>shared_ptr<T>shift_right(shared_ptr<T>first_value, shared_ptr<T>second_value) {
		return make_shared<T>(*first_value.get() >> *second_value.get());
	}

	shared_ptr<char>_and(shared_ptr<char>first_value, shared_ptr<char>second_value);
	shared_ptr<char>_or(shared_ptr<char>first_value, shared_ptr<char>second_value);
	shared_ptr<double>double_modulo(shared_ptr<double>first_value, shared_ptr<double>second_value);

	shared_ptr<char>chars_operations(shared_ptr<char>first_value, shared_ptr<char>second_value, string _operator);
	shared_ptr<double>floats_operations(shared_ptr<double>first_value, shared_ptr<double>second_value, string _operator);
	shared_ptr<long long int>ints_operations(shared_ptr<long long int>first_value, shared_ptr<long long int>second_value, string _operator);
	shared_ptr<string>strings_operations(shared_ptr<string>first_value, shared_ptr<string>second_value, string _operator);

	template <typename T>shared_ptr<char>compare(shared_ptr<T>first_value, shared_ptr<T>second_value, string _operator) {
		if (_operator == "==") {
			return equal<T>(first_value, second_value);
		}
		if (_operator == ">=") {
			return grader_or_equal<T>(first_value, second_value);
		}
		if (_operator == ">") {
			return grader_than<T>(first_value, second_value);
		}
		if (_operator == "<=") {
			return less_or_equal<T>(first_value, second_value);
		}
		if (_operator == "<") {
			return less_than<T>(first_value, second_value);
		}
		if (_operator == "!=") {
			return not_equal<T>(first_value, second_value);
		}
		return nullptr;
	}

}

