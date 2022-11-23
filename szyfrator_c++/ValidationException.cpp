#include <string>
#include "ValidationException.h"

template <typename T>
ValidationException<T>::ValidationException<T>(const std::string& msg, const T& value)
	: msg_{ msg }, value_{ value } {}

template <typename T>
const char* ValidationException<T>::what() const noexcept {
	return ("ValdationException: " + msg_ + " Failure value: " + value_).c_str();
}