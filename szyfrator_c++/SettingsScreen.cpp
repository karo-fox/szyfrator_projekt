#include <string>

#include "screens.h"
#include "SettingsScreen.h"
#include "Settings.h"

Language SettingsScreen::get_language_() const {
	SettingsScreen::ui_.show_text("Choose language:\npl - Polski\nen - English");
	auto language = SettingsScreen::ui_.text_input();
	if (language == "en") {
		return Language::en;
	}
	else if (language == "pl") {
		return Language::pl;
	}
}

ScreenType SettingsScreen::run() const {
	SettingsScreen::show_title("Settings\nlanguage: English\nsave to file: no");
	while (true) {
		SettingsScreen::ui_.show_text(SettingsScreen::actions_prompt_);
		std::string input = SettingsScreen::ui_.text_input();
		if (input == "language") {
			SettingsScreen::ui_.settings_.lang = SettingsScreen::get_language_();
			return ScreenType::stay;
		}
		else if (input == "file") {
			SettingsScreen::ui_.settings_.save_to_file_ = !SettingsScreen::ui_.settings_.save_to_file_;
			return ScreenType::stay;
		}
		else if (SettingsScreen::change_screen_.contains(input)) {
			return SettingsScreen::change_screen_.at(input);
		}
		else {
			SettingsScreen::ui_.show_text(
				"Action not found. Make sure you typed the option correctly and try again:"
			);
		}
	}
}