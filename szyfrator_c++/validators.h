#pragma once

#include <string>
#include <vector>

void validate_max_length(const std::string& value, int maxLength);
void validate_not_empty(const std::string& value);
void validate_allowed(const std::string& value, std::vector<std::string> allowed);

void validate_not_0(int value);
void validate_max_value(int value, int max);
void validate_min_value(int value, int min);