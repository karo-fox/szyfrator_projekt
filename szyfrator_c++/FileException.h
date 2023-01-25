#pragma once

#include <fstream>
#include <string>

#include "Exception.h"

/// <summary>
/// Exception class for file exceptions
/// Holds file that caused exception
/// </summary>
class FileException : public Exception {
private:

	/// <summary>
	/// The file that caused the exception
	/// </summary>
	std::ofstream& file_;
public:
	FileException(const std::string& msg, std::ofstream& file)
		: Exception{ msg }, file_{ file } {};
};
