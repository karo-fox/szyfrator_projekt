#pragma once

#include <string>
#include <vector>

/// <summary>
/// Splits string according to provided separator 
///</summary>
/// <param name="str">String to be split</param> 
/// <param name="sep">Separator</param> 
/// <returns>Vector containing string fragments</returns>
std::vector<std::string> split_str(const std::string& str, char sep);

/// <summary>
/// Splits string into pairs of characters
/// </summary>
/// <param name="str">String to be split</param>
/// <returns>Vector containing string fragments</returns>
std::vector<std::string> split_in_pairs(const std::string& str);

/// <summary>
/// Converts all string characters to lowercase
/// </summary>
/// <param name="str">String to convert</param>
/// <returns>String in lowercase</returns>
std::string str_to_lower(const std::string& str);

/// <summary>
/// Checks if the vector contains only ""
/// </summary>
/// <param name="vec">Vector to check</param>
/// <returns>Boolean</returns>
bool vec_is_empty(std::vector<std::string> vec);

/// <summary>
/// Adds add_str to an unique_str ommiting duplicate characters
/// </summary>
/// <param name="add_str">The string to be added</param>
/// <param name="unique_str">The base string with unique characters</param>
/// <returns>Combined string</returns>
std::string unique_combine(
	const std::string& add_str, const std::string& unique_str = ""
);
