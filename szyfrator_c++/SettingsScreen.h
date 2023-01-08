#pragma once

#include <map>
#include <string>

#include "screens.h"
#include "UserInterface.h"
#include "SettingsScreenCommunicator.h"

/// <summary>
/// Settings screen
/// </summary>
class SettingsScreen : public Screen {
private:
	const std::map<std::string, ScreenType> change_screen_{
		{"back", ScreenType::back}
	};

	const SettingsScreenCommunicator communicator_;
public:
	SettingsScreen(UserInterface& ui) : Screen{ ui }, communicator_{ ui } {};
	/// <summary>
	/// Presents some actions for user to take:
	/// - change language
	/// - set the option of saving output to file
	/// - go back
	/// </summary>
	/// <returns>Screen that should be run next</returns>
	ScreenType run() const override;
};