#pragma once

#include <string>
#include "UserInterface.h"

/// <summary>
/// Available types of Screens
/// </summary>
enum ScreenType {
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
	const UserInterface& ui_;
public:
	Screen(const UserInterface& ui) : ui_{ ui } {};
	/// <summary>
	/// Presents some actions for user to take and manages them
	/// </summary>
	/// <returns>Screen that should be run next</returns>
	virtual ScreenType run() const = 0;
	void show_title(const std::string& title) const;
};