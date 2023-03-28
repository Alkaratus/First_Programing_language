#pragma once
#include <variant>
#include <string>
#include <memory>
#include <stdexcept>

using std::shared_ptr, std::string;

typedef std::variant<shared_ptr<char>, shared_ptr<double>, shared_ptr<long long int>, shared_ptr<string>> value;

struct Assign {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	value operator()(shared_ptr<double> first, shared_ptr<double> second);
	value operator()(shared_ptr<long long int> first, shared_ptr<long long int> second);
	value operator()(shared_ptr<string> first, shared_ptr<string> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct Equal {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	value operator()(shared_ptr<double> first, shared_ptr<double> second);
	value operator()(shared_ptr<long long int> first, shared_ptr<long long int> second);
	value operator()(shared_ptr<string> first, shared_ptr<string> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct Not_Equal {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	value operator()(shared_ptr<double> first, shared_ptr<double> second);
	value operator()(shared_ptr<long long int> first, shared_ptr<long long int> second);
	value operator()(shared_ptr<string> first, shared_ptr<string> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct Grader_Or_Equal {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	value operator()(shared_ptr<double> first, shared_ptr<double> second);
	value operator()(shared_ptr<long long int> first, shared_ptr<long long int> second);
	value operator()(shared_ptr<string> first, shared_ptr<string> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct Grader_Than {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	value operator()(shared_ptr<double> first, shared_ptr<double> second);
	value operator()(shared_ptr<long long int> first, shared_ptr<long long int> second);
	value operator()(shared_ptr<string> first, shared_ptr<string> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct Less_Or_Equal {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	value operator()(shared_ptr<double> first, shared_ptr<double> second);
	value operator()(shared_ptr<long long int> first, shared_ptr<long long int> second);
	value operator()(shared_ptr<string> first, shared_ptr<string> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct Less_Than {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	value operator()(shared_ptr<double> first, shared_ptr<double> second);
	value operator()(shared_ptr<long long int> first, shared_ptr<long long int> second);
	value operator()(shared_ptr<string> first, shared_ptr<string> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct Summation {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	value operator()(shared_ptr<double> first, shared_ptr<double> second);
	value operator()(shared_ptr<long long int> first, shared_ptr<long long int> second);
	value operator()(shared_ptr<string> first, shared_ptr<string> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct Division {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	value operator()(shared_ptr<double> first, shared_ptr<double> second);
	value operator()(shared_ptr<long long int> first, shared_ptr<long long int> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct Modulation {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	value operator()(shared_ptr<double> first, shared_ptr<double> second);
	value operator()(shared_ptr<long long int> first, shared_ptr<long long int> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct Multiplication {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	value operator()(shared_ptr<double> first, shared_ptr<double> second);
	value operator()(shared_ptr<long long int> first, shared_ptr<long long int> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct Subtraction {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	value operator()(shared_ptr<double> first, shared_ptr<double> second);
	value operator()(shared_ptr<long long int> first, shared_ptr<long long int> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct Bin_And {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	value operator()(shared_ptr<long long int> first, shared_ptr<long long int> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct Bin_Or {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	value operator()(shared_ptr<long long int> first, shared_ptr<long long int> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct Bin_Xor {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	value operator()(shared_ptr<long long int> first, shared_ptr<long long int> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct Shift_Left {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	value operator()(shared_ptr<long long int> first, shared_ptr<long long int> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct Shift_Right {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	value operator()(shared_ptr<long long int> first, shared_ptr<long long int> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct _Or {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};

struct _And {
	value operator()(shared_ptr<char> first, shared_ptr<char> second);
	template<typename U, typename V>
	[[noreturn]] value operator()(U u, V v) {
		throw std::runtime_error("");
	}
};