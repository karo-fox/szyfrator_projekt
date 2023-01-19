#include <string>
#include <iostream>

#include "ConsoleUI.h"
#include "lang.h"

void ConsoleUI::ignore_line() const {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

template <typename T>
T ConsoleUI::safe_input(const std::string& prompt) const {
	while (true) {
		T input{};
		std::cout << prompt;
		std::cin >> input;

		if (!std::cin) {
			std::cin.clear();
			ignore_line();
			std::cout << parse(LangCode::invalid_input) << '\n';
		}
		else {
			ignore_line();
			return input;
		}
	}
}

template <>
std::string ConsoleUI::safe_input(const std::string& prompt) const {
	std::string input{};
	std::cout << prompt;
	std::getline(std::cin, input);
	return input;
}

std::string ConsoleUI::text_input() const {
	return safe_input<std::string>(ConsoleUI::iprompt_);
}

int ConsoleUI::integer_input() const {
	return safe_input<int>(ConsoleUI::iprompt_);
}

bool ConsoleUI::bool_input() const {
	while (true) {
		std::string input = safe_input<std::string>(ConsoleUI::iprompt_);
		if (input == "y" || input == "Y") {
			return true;
		}
		else if (input == "n" || input == "N") {
			return false;
		}
		std::cout << parse(LangCode::invalid_input) << '\n';
	}	
}

void ConsoleUI::show_text(const std::string& text) const {
	std::cout << '\n' << text << '\n';
}