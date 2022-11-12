#pragma once

#include <string>

class UserInterface {
public:
	virtual std::string text_input() const = 0;
	virtual int integer_input() const = 0;
	virtual bool check_input() const = 0;
	virtual void show_text(std::string text) const = 0;
};