#include <string>

#include "screens.h"
#include "SettingsScreen.h"

ScreenType SettingsScreen::run() const {
	SettingsScreen::show_title("Settings");
	while (true) {
		std::string input = SettingsScreen::ui_.text_input();
		if (input == "back") {
			return ScreenType::back;
		}
		else {
			SettingsScreen::ui_.show_text(input);
		}
	}
}