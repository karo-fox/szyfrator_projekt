#include <string>

#include "SettingsScreenCommunicator.h"
#include "Settings.h"
#include "validators.h"
#include "ValidationException.h"

LangCode SettingsScreenCommunicator::get_save_to_file_code_() const {
	if (ui_.settings_.save_to_file_) {
		return LangCode::yes;
	}
	return LangCode::no;
}

Language SettingsScreenCommunicator::get_language() const {
	while (true) {
		ui_.show_text(
			ui_.parse(LangCode::choose_language) + "\n[pl] - Polski\n[en] - English"
		);
		std::string input = ui_.text_input();
		try {
			validate_not_empty(input);
			validate_allowed(input, { "pl", "en" });
			if (input == "en") {
				return Language::en;
			}
			else if (input == "pl") {
				return Language::pl;
			}
		}
		catch (const ValidationException<std::string>& e) {
			ui_.show_text(ui_.parse(e.msg_code_, e.validation_args_));
		}
	}
};
