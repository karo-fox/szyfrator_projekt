#include <string>

#include "EncryptionScreen.h"
#include "screens.h"

ScreenType EncryptionScreen::run() const {
	EncryptionScreen::show_title("Encryption");
	while (true) {
		EncryptionScreen::ui_.show_text(EncryptionScreen::actions_prompt_);
		std::string input = EncryptionScreen::ui_.text_input();
		if (input == "start") {
			return ScreenType::stay;
		}
		else if (EncryptionScreen::change_screen_.contains(input)) {
			return EncryptionScreen::change_screen_.at(input);
		}
		else {
			EncryptionScreen::ui_.show_text(
				"Action not found. Make sure you typed the option correctly and try again:"
			);
		}
	}
}