#include <string>

#include "EncryptionScreen.h"
#include "screens.h"
#include "lang.h"

ScreenType EncryptionScreen::run() const {
	communicator_.show_title(ui_.parse(LangCode::encryption_title));
	while (true) {
		communicator_.show_actions();
		std::string input = communicator_.get_action();
		if (input == "start") {
			return ScreenType::stay;
		}
		else if (change_screen_.contains(input)) {
			return change_screen_.at(input);
		}
		else {
			communicator_.action_not_found();
		}
	}
}