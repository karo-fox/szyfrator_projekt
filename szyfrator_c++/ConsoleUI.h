#pragma once

#include <string>
#include "UserInterface.h"

/// <summary>
/// User Interface for Console
/// </summary>
class ConsoleUI : public UserInterface {
private:
	/// <summary>
	/// Gets input from user & checks for failed extractions
	/// </summary>
	/// <typeparam name="T">Type of input, e.g. int, bool, std::string</typeparam>
	/// <param name="prompt">Prompt to show when program asks for input</param>
	/// <returns>Correct input of type T</returns>
	template <typename T>
	T safe_input(const std::string& prompt) const;

	/// <summary>
	/// Removes invalid input
	/// </summary>
	void ignore_line() const;

	/// <summary>
	/// console prompt for input
	/// </summary>
	const std::string iprompt_{ ":> " };

	/// <summary>
	/// console prompt for output
	/// </summary>
	const std::string oprompt_{ "<: " };
public:
	std::string text_input() const override;
	int integer_input() const override;
	bool bool_input() const override;
	void show_text(const std::string& text) const override;

	/// <summary>
	/// Shows the title of the screen
	/// </summary>
	/// <param name="title">Title to show</param>
	void show_title(const std::string& title) const;
};