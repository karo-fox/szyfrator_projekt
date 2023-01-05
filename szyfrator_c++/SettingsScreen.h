#pragma once

#include "screens.h"
#include "UserInterface.h"

/// <summary>
/// Settings screen
/// </summary>
class SettingsScreen : public Screen {
public:
	SettingsScreen(const UserInterface& ui) : Screen{ ui } {};
	/// <summary>
	/// Presents some actions for user to take:
	/// - change language
	/// - set the option of saving output to file
	/// - go back
	/// </summary>
	/// <returns>Screen that should be run next</returns>
	ScreenType run() const override;
};