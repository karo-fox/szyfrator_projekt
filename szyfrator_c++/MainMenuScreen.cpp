#include <string>

#include "screens.h"
#include "MainMenuScreen.h"

ScreenType MainMenuScreen::run() const {
	MainMenuScreen::show_title("Main menu");
	while (true) {
		MainMenuScreen::ui_.show_text(MainMenuScreen::actions_prompt_);
		std::string input = MainMenuScreen::ui_.text_input();
		if (input == "quit") {
			exit(0);
			return ScreenType::stay;
		}
		else if (MainMenuScreen::change_screen_.contains(input)) {
			return MainMenuScreen::change_screen_.at(input);
		}
		else {
			MainMenuScreen::ui_.show_text(
				"Action not found. Make sure you typed the option correctly and try again:"
			);
		}
	}

}