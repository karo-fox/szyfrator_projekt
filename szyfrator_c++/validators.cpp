#include <string>
#include <vector>
#include "ValidationException.h"
#include "validators.h"

void validateMaxLength(const std::string& value, int maxLength) {
	if (value.length() > 0) {
		throw ValidationException<std::string>(
			"Cannot exceed max length, (max length: " + maxLength + ')', value
		);
	}
};

void validateNotEmpty(const std::string& value) {
	if (value.empty()) {
		throw ValidationException<std::string>(
			"Cannot be empty", value
			);
	}
}

void validateAllowed(const std::string& value, std::vector<std::string> allowed) {
	for (const std::string option : allowed) {
		if (value == option) {
			return;
		}
	}
	throw ValidationException<std::string>(
		"Input not allowed", value
		);
}

void validateNot0(int value) {
	if (value == 0) {
		throw ValidationException<int>(
			"Cannot be 0", value
			);
	}
}

void validateMaxValue(int value, int max) {
	if (value > max) {
		throw ValidationException<int>(
			"Cannot be greater than " + std::to_string(max), value
			);
	}
}

void validateMinValue(int value, int min) {
	if (value < min) {
		throw ValidationException<int>(
			"Cannot be less than " + std::to_string(min), value
			);
	}
}
