#pragma once

#include "screens.h"
#include "UserInterface.h"

/// <summary>
/// Main Menu Screen for the program
/// </summary>
class MainMenuScreen : public Screen {
public:
	MainMenuScreen(const UserInterface& ui) : Screen{ ui } {};
	/// <summary>
	/// Presents some actions for user to take:
	/// - go to settings
	/// - start encrypting/decrypting
	/// - quit
	/// </summary>
	/// <returns>Screen that should be run next</returns>
	ScreenType run() const override;
};
