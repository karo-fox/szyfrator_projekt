#pragma once

#include <map>
#include <string>

#include "lang.h"

std::map<LangCode, std::string> english{
	{ LangCode::yes, "yes" },
	{ LangCode::no, "no" },
	{ LangCode::current_language, "English" },
	{ LangCode::menu_title, "Main Menu" },
	{ LangCode::encryption_title, "Encryption" },
	{ LangCode::settings_title, "Settings" },
	{ LangCode::show_language, "Language" },
	{ LangCode::save_to_file, "Save to file" },
	{ LangCode::choose_language, "Choose language" },
	{ LangCode::menu_screen_actions,
		"Choose one of the following actions:\n"
		"settings: go to settings\n"
		"encryption: encrypt or decrypt message\n"
		"quit: quit\n" },
	{ LangCode::encryption_screen_actions,
		"start: start decrypting / encrypting the message\n"
		"back: go to main menu\n" },
	{ LangCode::settings_screen_actions,
		"language: change interface langauge\n"
		"file: enable / disable saving to file\n"
		"back: return to main menu\n" },
	{ LangCode::available_actions, "Available actions" },
	{ LangCode::choose_action, "Choose action" },
	{ LangCode::action_not_found,
		"Action not found. Make sure you typed the option correctly and try again" },
	{ LangCode::set_offset, "Set offset" },
	{ LangCode::set_direction, "Set direction (right or left)" },
	{ LangCode::invalid_input, "Invalid input. Try again" },
	{ LangCode::v_max_length, "Cannot exceed max length, max length" },
	{ LangCode::v_not_empty, "Cannot be empty" },
	{ LangCode::v_allowed, "Input not allowed" },
	{ LangCode::v_not_0, "Cannot be 0" },
	{ LangCode::v_max_value, "Cannot be greater than" },
	{ LangCode::v_min_value, "Cannot be less than" },
};