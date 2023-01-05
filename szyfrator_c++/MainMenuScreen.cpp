#include <string>

#include "screens.h"
#include "MainMenuScreen.h"

ScreenType MainMenuScreen::run() const {
	MainMenuScreen::show_title("Main menu");
	while (true) {
		std::string input = MainMenuScreen::ui_.text_input();
		if (input == "settings") {
			return ScreenType::settings;
		}
		else if (input == "encryption") {
			return ScreenType::encryption;
		}
		else {
			MainMenuScreen::ui_.show_text(input);
		}
	}

}