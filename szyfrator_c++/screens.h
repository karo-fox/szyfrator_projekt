#pragma once

#include <string>
#include "UserInterface.h"

enum ScreenType {
	main_menu,
	settings,
	encryption,
	back,
};

class Screen {
public:
	virtual ScreenType run() const = 0;
};

class MainMenu : public Screen {
private:
	const UserInterface& ui_;
public:
	MainMenu(const UserInterface& ui) : ui_{ ui } {};
	ScreenType run() const;
};
