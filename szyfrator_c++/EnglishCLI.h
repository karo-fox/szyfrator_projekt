#pragma once

#include <string>
#include "UserInterface.h"

class EnglishCLI : public UserInterface {
public:
	std::string text_input() const override;
	int integer_input() const override;
	bool check_input() const override;
	void show_text(std::string text) const override;
};