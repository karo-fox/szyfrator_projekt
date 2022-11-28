#pragma once

#include <string>
#include <stdexcept>

template <typename T>
class ValidationException : public std::runtime_error {
private:
	const T& value_{};
public:
	ValidationException(const std::string& msg, const T& value)
		: std::runtime_error{msg.c_str()}, value_{value} {};
};