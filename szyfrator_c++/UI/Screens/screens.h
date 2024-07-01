#pragma once

#include <string>
#include <map>

#include "UserInterface.h"
#include "Settings.h"

/// <summary>
/// Available types of Screens
/// </summary>
enum class ScreenType {
	main_menu,
	settings,
	encryption,
	back,
	stay,
};

/// <summary>
/// Each Screen represents some actions user can take
/// </summary>
class Screen {
protected:
	UserInterface& ui_;
	/// <summary>
	/// Maps user input to next Screen that should be presentd
	/// </summary>
	const std::map<std::string, ScreenType> change_screen_{};
	const std::string actions_prompt_{};
public:
	Screen(UserInterface& ui) : ui_{ ui } {};
	/// <summary>
	/// Presents some actions for user to take and manages them
	/// </summary>
	/// <returns>Screen that should be run next</returns>
	virtual ScreenType run() const = 0;
};
