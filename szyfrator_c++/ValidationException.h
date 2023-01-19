#pragma once

#include <string>
#include <stdexcept>
#include <vector>

#include "lang.h"

/// <summary>
/// Exception for validation failures
/// </summary>
/// <typeparam name="T">Type of the validated value</typeparam>
template <typename T>
class ValidationException : public std::runtime_error {
private:
	const T& value_{};
public:
	const std::vector<int> validation_args_{};
	const LangCode msg_code_{};

	ValidationException(
		const std::string& msg, 
		const T& value, 
		const std::vector<int> args,
		const LangCode msg_code
	) : 
		std::runtime_error{ msg.c_str() }, 
		value_{ value }, 
		validation_args_{ args },
		msg_code_{ msg_code }
	{};
};