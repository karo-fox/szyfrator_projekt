#include <string>
#include <iostream>

#include "EnglishCLI.h"

void EnglishCLI::ignoreLine() const {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
T EnglishCLI::saveInput(const std::string & prompt) const {
	while (true) {
		T input{};
		std::cout << prompt;
		std::cin >> input;

		if (!std::cin) {
			std::cin.clear();
			ignoreLine();
			std::cout << "Invalid input. Try again. \n";
		}
		else {
			ignoreLine();
			return input;
		}
	}
}

std::string EnglishCLI::text_input() const {
	return saveInput<std::string>(":> ");
}

int EnglishCLI::integer_input() const {
	return saveInput<int>(":> ");
}

bool EnglishCLI::check_input() const {
	while (true) {
		std::string input = saveInput<std::string>(":> ");
		if (input == "y" || input == "Y") {
			return true;
		}
		else if (input == "n" || input == "N") {
			return false;
		}
		std::cout << "Invalid input. Try again\n";
	}	
}

void EnglishCLI::show_text(const std::string& text) const {
	std::cout << "<: " << text << '\n';
}