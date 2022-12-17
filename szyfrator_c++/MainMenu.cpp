#pragma once

#include <string>

#include "screens.h"
#include "UserInterface.h"

ScreenType MainMenu::run() const {
	MainMenu::ui_.show_text("Main menu\n");
	while (true) {
		std::string input = MainMenu::ui_.text_input();
		if (input == "back") {
			return ScreenType::main_menu;
		}
		else {
			MainMenu::ui_.show_text(input);
		}
	}

}