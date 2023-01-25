#pragma once

#include <stdexcept>
#include <string>

/// <summary>
/// Base class for exceptions
/// </summary>
class Exception : public std::runtime_error {
public:
	Exception(const std::string& msg) : std::runtime_error{ msg.c_str() } {};
};
