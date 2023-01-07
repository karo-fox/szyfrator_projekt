#pragma once

#include <map>
#include <string>

#include "screens.h"
#include "UserInterface.h"

/// <summary>
/// Main Menu Screen for the program
/// </summary>
class MenuScreen : public Screen {
private:
	const std::map<std::string, ScreenType> change_screen_{
		{"settings", ScreenType::settings},
		{"encryption", ScreenType::encryption},
	};
	const std::string actions_prompt_{
		"Choose one of the following actions:\n"
		"settings: go to settings\n"
		"encryption: encrypt or decrypt message\n"
		"quit: quit\n"
	};
public:
	MenuScreen(UserInterface& ui) : Screen{ ui } {};
	/// <summary>
	/// Presents some actions for user to take:
	/// - go to settings
	/// - start encrypting/decrypting
	/// - quit
	/// </summary>
	/// <returns>Screen that should be run next</returns>
	ScreenType run() const override;
};
