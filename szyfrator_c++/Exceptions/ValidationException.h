#pragma once

#include <string>
#include <vector>

#include "Exception.h"
#include "lang.h"

/// <summary>
/// Exception for Validation failures
/// Holds the value that caused the exception
/// </summary>
/// <typeparam name="T">Type of the validated value</typeparam>
template <typename T>
class ValidationException : public Exception {
private:
	/// <summary>
	/// The value that caused the exception
	/// </summary>
	const T& value_{};
public:
	/// <summary>
	/// Argument used in validation
	/// </summary>
	const std::vector<int> validation_args_{};

	/// <summary>
	/// Code of the message presented to user
	/// </summary>
	const LangCode msg_code_{};

	ValidationException(
		const std::string& msg, 
		const T& value, 
		const std::vector<int> args,
		const LangCode msg_code
	) : 
		Exception{ msg },
		value_{ value }, 
		validation_args_{ args },
		msg_code_{ msg_code }
	{};
};
