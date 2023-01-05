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
};

/// <summary>
/// Abstract class for Screens
/// Each Screen represents some actions user can take
/// </summary>
class Screen {
public:
	/// <summary>
	/// Presents some actions for user to take and manages them
	/// </summary>
	/// <returns>Screen that should be run next</returns>
	virtual ScreenType run() const = 0;
};