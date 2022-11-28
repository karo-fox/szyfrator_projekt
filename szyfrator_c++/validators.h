#pragma once

#include <string>
#include <vector>

void validateMaxLength(const std::string& value, int maxLength);
void validateNotEmpty(const std::string& value);
void validateAllowed(const std::string& value, std::vector<std::string> allowed);

void validateNot0(int value);
void validateMaxValue(int value, int max);
void validateMinValue(int value, int min);