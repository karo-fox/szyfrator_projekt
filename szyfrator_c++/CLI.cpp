#include <string>
#include <iostream>

#include "CLI.h"

void CLI::ignoreLine() const {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
T CLI::saveInput(const std::string& prompt) const {
	while (true) {
		T input{};
		std::cout << prompt;
		std::cin >> input;

		if (!std::cin) {
			std::cin.clear();
			ignoreLine();
			std::cout << CLI::oprompt_ << "Invalid input. Try again. \n";
		}
		else {
			ignoreLine();
			return input;
		}
	}
}

template <>
std::string CLI::saveInput(const std::string& prompt) const {
	std::string input{};
	std::cout << prompt;
	std::getline(std::cin, input);
	return input;
}

std::string CLI::text_input() const {
	return saveInput<std::string>(CLI::iprompt_);
}

int CLI::integer_input() const {
	return saveInput<int>(CLI::iprompt_);
}

bool CLI::check_input() const {
	while (true) {
		std::string input = saveInput<std::string>(CLI::iprompt_);
		if (input == "y" || input == "Y") {
			return true;
		}
		else if (input == "n" || input == "N") {
			return false;
		}
		std::cout << CLI::oprompt_ << "Invalid input. Try again\n";
	}	
}

void CLI::show_text(const std::string& text) const {
	std::cout << CLI::oprompt_ << text << '\n';
}