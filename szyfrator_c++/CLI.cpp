#include <string>
#include <iostream>

#include "CLI.h"

void CLI::ignore_line() const {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
T CLI::safe_input(const std::string& prompt) const {
	while (true) {
		T input{};
		std::cout << prompt;
		std::cin >> input;

		if (!std::cin) {
			std::cin.clear();
			ignore_line();
			std::cout << CLI::oprompt_ << "Invalid input. Try again. \n";
		}
		else {
			ignore_line();
			return input;
		}
	}
}

template <>
std::string CLI::safe_input(const std::string& prompt) const {
	std::string input{};
	std::cout << prompt;
	std::getline(std::cin, input);
	return input;
}

std::string CLI::text_input() const {
	return safe_input<std::string>(CLI::iprompt_);
}

int CLI::integer_input() const {
	return safe_input<int>(CLI::iprompt_);
}

bool CLI::check_input() const {
	while (true) {
		std::string input = safe_input<std::string>(CLI::iprompt_);
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