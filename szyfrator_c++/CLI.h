#pragma once

#include <string>
#include "UserInterface.h"

class CLI : public UserInterface {
private:
	template <typename T>
	T safe_input(const std::string& prompt) const;
	void ignore_line() const;
	const std::string iprompt_{ ":> " };
	const std::string oprompt_{ "<: " };
public:
	std::string text_input() const override;
	int integer_input() const override;
	bool check_input() const override;
	void show_text(const std::string& text) const override;
};