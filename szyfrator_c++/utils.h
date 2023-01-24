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

std::vector<std::string> split_in_pairs(const std::string& str);

std::string str_to_lower(const std::string& str);