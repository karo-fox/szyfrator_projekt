#pragma once

#include <map>
#include <string>

#include "screens.h"
#include "UserInterface.h"

/// <summary>
/// Settings screen
/// </summary>
class SettingsScreen : public Screen {
private:
	const std::map<std::string, ScreenType> change_screen_{
		{"back", ScreenType::back}
	};
	const std::string actions_prompt_{
		"language: change interface langauge\n"
		"file: enable / disable saving to file\n"
		"back: return to main menu"
	};

	Language get_language_() const;
public:
	SettingsScreen(UserInterface& ui) : Screen{ ui } {};
	/// <summary>
	/// Presents some actions for user to take:
	/// - change language
	/// - set the option of saving output to file
	/// - go back
	/// </summary>
	/// <returns>Screen that should be run next</returns>
	ScreenType run() const override;
};