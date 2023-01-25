#pragma once

#include <string>
#include <vector>

#include "Settings.h"
#include "lang.h"

/// <summary>
/// Manages User Interface
/// </summary>
class UserInterface {
private:
	/// <summary>
	/// Map of possible translations
	/// </summary>
	const langMap translations_;

	/// <summary>
	/// Sets up a map of possible translations
	/// </summary>
	/// <returns>A map of possible translations</returns>
	langMap setup_lang_();
public:
	UserInterface() : translations_{ setup_lang_() } {};

	/// <summary>
	/// User settings
	/// </summary>
	Settings settings_{};
	
	/// <summary>
	/// Parses the code of the prompt into the translation
	/// </summary>
	/// <param name="code">Code of the prompt</param>
	/// <returns>Translated prompt</returns>
	std::string parse(LangCode code) const;

	/// <summary>
	/// Parses the code of the prompt into the translation
	/// </summary>
	/// <typeparam name="T">Type of the arguments of the prompt</typeparam>
	/// <param name="code">Code of the prompt</param>
	/// <param name="args">Arguments of the promp</param>
	/// <returns>Translated prompt</returns>
	template <typename T>
	std::string parse(LangCode code, std::vector<T> args) const;

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
