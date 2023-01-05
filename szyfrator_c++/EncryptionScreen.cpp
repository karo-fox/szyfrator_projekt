#include <string>

#include "EncryptionScreen.h"
#include "screens.h"

ScreenType EncryptionScreen::run() const {
	EncryptionScreen::show_title("Encryption");
	while (true) {
		std::string input = EncryptionScreen::ui_.text_input();
		if (input == "back") {
			return ScreenType::back;
		}
		else {
			EncryptionScreen::ui_.show_text(input);
		}
	}
}