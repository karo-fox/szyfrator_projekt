#include <string>
#include <iostream>
#include "EnglishCLI.h"

std::string EnglishCLI::text_input() const {
	std::string input{};
	std::cout << ":> ";
	std::cin >> input;
	return input;
}

int EnglishCLI::integer_input() const {
	int input{};
	std::cout << ":> ";
	std::cin >> input;
	return input;
}

bool EnglishCLI::check_input() const {
	return true;
}

void EnglishCLI::show_text(std::string text) const {
	std::cout << "<: " << text << '\n';
}