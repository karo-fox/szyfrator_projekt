#pragma once

#include <stdexcept>
#include <fstream>
#include <string>

class FileException : public std::runtime_error {
private:
	std::ofstream& file_;
public:
	FileException(const std::string& msg, std::ofstream& file)
		: std::runtime_error{ msg.c_str() }, file_{ file } {};
};