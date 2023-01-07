#pragma once

#include <string>

#include "Settings.h"

/// <summary>
/// Manages User Interface
/// </summary>
class UserInterface {
public:
	Settings settings_{};

	/// <summary>
	/// Gets text input from user
	/// </summary>
	/// <returns>Text user input</returns>
	virtual std::string text_input() const = 0;

	/// <summary>
	/// Gets integer input from user
	/// </summary>
	/// <returns>Integer user input</returns>
	virtual int integer_input() const = 0;

	/// <summary>
	/// Gets boolean input from user
	/// </summary>
	/// <returns>Boolean user input</returns>
	virtual bool bool_input() const = 0;

	/// <summary>
	/// Shows some text to user
	/// </summary>
	/// <param name="text">Text to show</param>
	virtual void show_text(const std::string& text) const = 0;
};