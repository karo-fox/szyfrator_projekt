#pragma once

#include <string>

void validateMaxLength(const std::string& value, int maxLength);
void validateNotEmpty(const std::string& value);

void validateNot0(int value);
void validateMaxValue(int value, int max);
void validateMinValue(int value, int min);

int getOne();