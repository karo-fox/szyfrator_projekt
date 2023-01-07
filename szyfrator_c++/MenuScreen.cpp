#include <string>

#include "screens.h"
#include "MenuScreen.h"

ScreenType MenuScreen::run() const {
	MenuScreen::show_title("Main menu");
	while (true) {
		MenuScreen::ui_.show_text(MenuScreen::actions_prompt_);
		std::string input = MenuScreen::ui_.text_input();
		if (input == "quit") {
			exit(0);
			return ScreenType::stay;
		}
		else if (MenuScreen::change_screen_.contains(input)) {
			return MenuScreen::change_screen_.at(input);
		}
		else {
			MenuScreen::ui_.show_text(
				"Action not found. Make sure you typed the option correctly and try again:"
			);
		}
	}

}