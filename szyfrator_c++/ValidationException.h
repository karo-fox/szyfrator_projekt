#pragma once

#include <string>
#include <exception>

template <typename T>
class ValidationException : public std::exception {
private:
	const T& value_{};
	const std::string& msg_{};
public:
	ValidationException(const std::string& msg, const T& value_);
	const char* what() const noexcept override;
};