#include <string>

#include "screens.h"
#include "SettingsScreen.h"
#include "Settings.h"
#include "lang.h"

ScreenType SettingsScreen::run() const {
	std::string title = ui_.parse(LangCode::settings_title) + '\n' + 
		ui_.parse(LangCode::show_language) + ": " + ui_.parse(LangCode::current_language) + 
		'\n' + ui_.parse(LangCode::save_to_file) + ": " + 
		ui_.parse(communicator_.get_save_to_file_code_());
	communicator_.show_title(title);
	while (true) {
		communicator_.show_actions();
		std::string input = communicator_.get_action();
		if (input == "language") {
			ui_.settings_.lang = communicator_.get_language();
			return ScreenType::stay;
		}
		else if (input == "file") {
			ui_.settings_.save_to_file_ = !ui_.settings_.save_to_file_;
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
