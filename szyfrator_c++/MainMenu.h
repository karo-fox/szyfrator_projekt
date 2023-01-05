#pragma once

#include "screens.h"
#include "UserInterface.h"

/// <summary>
/// Main Menu Screen for the program
/// </summary>
class MainMenu : public Screen {
private:
	const UserInterface& ui_;
public:
	MainMenu(const UserInterface& ui) : ui_{ ui } {};

	/// <summary>
	/// Presents some actions for user to take:
	/// - go to settings
	/// - start encrypting/decrypting
	/// - quit
	/// </summary>
	/// <returns>Screen that should be run next</returns>
	ScreenType run() const;
};
