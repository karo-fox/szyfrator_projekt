#pragma once

#include <string>
#include <vector>

/// <summary>
/// Vaidate if string does not exceed max length
/// </summary>
/// <param name="value">String to validate</param>
/// <param name="maxLength">Max length limit</param>
void validate_max_length(const std::string& value, int maxLength);

/// <summary>
/// Validate if string is not empty
/// </summary>
/// <param name="value">String to validate</param>
void validate_not_empty(const std::string& value);

/// <summary>
/// Validate if string is one of the allowed options
/// </summary>
/// <param name="value">String to validate</param>
/// <param name="allowed">Vector of allowed strings</param>
void validate_allowed(const std::string& value, std::vector<std::string> allowed);



/// <summary>
/// Validate if integer is not 0
/// </summary>
/// <param name="value">Integer to validate</param>
void validate_not_0(int value);

/// <summary>
/// Validate if integer is not greater than maximal allowed number
/// </summary>
/// <param name="value">Integer to validate</param>
/// <param name="max">Maximal allowed number</param>
void validate_max_value(int value, int max);

/// <summary>
/// Validate if integer is not less than minimal allowed number
/// </summary>
/// <param name="value">Integer to validate</param>
/// <param name="min">Minimal allowed number</param>
void validate_min_value(int value, int min);