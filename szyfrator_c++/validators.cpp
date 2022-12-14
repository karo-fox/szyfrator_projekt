#include <string>
#include <vector>
#include "ValidationException.h"
#include "validators.h"

void validate_max_length(const std::string& value, int max_length) {
	if (value.length() > max_length) {
		throw ValidationException<std::string>(
			"Cannot exceed max length, (max length: " + max_length + ')', value
		);
	}
};

void validate_not_empty(const std::string& value) {
	if (value.empty()) {
		throw ValidationException<std::string>(
			"Cannot be empty", value
			);
	}
}

void validate_allowed(const std::string& value, std::vector<std::string> allowed) {
	for (const std::string option : allowed) {
		if (value == option) {
			return;
		}
	}
	throw ValidationException<std::string>(
		"Input not allowed", value
		);
}




void validate_not_0(int value) {
	if (value == 0) {
		throw ValidationException<int>(
			"Cannot be 0", value
			);
	}
}

void validate_max_value(int value, int max) {
	if (value > max) {
		throw ValidationException<int>(
			"Cannot be greater than " + std::to_string(max), value
			);
	}
}

void validate_min_value(int value, int min) {
	if (value < min) {
		throw ValidationException<int>(
			"Cannot be less than " + std::to_string(min), value
			);
	}
}
