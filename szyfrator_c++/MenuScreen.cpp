#include <string>

#include "screens.h"
#include "MenuScreen.h"
#include "lang.h"

ScreenType MenuScreen::run() const {
	communicator_.show_title(ui_.parse(LangCode::menu_title));
	while (true) {
		communicator_.show_actions();
		std::string input = communicator_.get_action();
		if (input == "quit") {
			exit(0);
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