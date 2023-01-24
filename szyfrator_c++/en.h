#pragma once

#include <map>
#include <string>

#include "lang.h"

std::map<LangCode, std::string> english{
	// general codes
	{ LangCode::yes, "yes" },
	{ LangCode::no, "no" },
	{ LangCode::current_language, "English" },
	{ LangCode::invalid_input, "Invalid input. Try again" },
	{ LangCode::key_continue, "Press 'enter' to continue" },
	// screen titles codes
	{ LangCode::main_title, "Main Menu" },
	{ LangCode::settings_title, "Settings" },
	// main screen codes
	{ LangCode::file_saved, "Successfully saved result to file" },
	// setttings screen codes
	{ LangCode::show_language, "Language" },
	{ LangCode::save_to_file, "Save to file" },
	{ LangCode::choose_language, "Choose language" },
	// screen actions codes
	{ LangCode::main_screen_actions,
		"[settings]: go to settings\n"
		"[start]: encrypt or decrypt message\n"
		"[quit]: quit\n" },
	{ LangCode::settings_screen_actions,
		"[language]: change interface langauge\n"
		"[file]: enable / disable saving to file\n"
		"[back]: return to main screen\n" },
	{ LangCode::available_screen_actions, "Available actions" },
	{ LangCode::choose_screen_action, "Choose action" },
	{ LangCode::action_not_found,
		"Action not found. Make sure you typed the option correctly and try again" },
	// cipher choice codes
	{ LangCode::choose_cipher, "Choose one of the following ciphers" },
	{ LangCode::available_ciphers,
		"[ceasar]: Ceasar's cipher\n"
		"[four square]: Four Square cipher" },
	// other encryption codes
	{ LangCode::result, "Your result" },
	{ LangCode::provide_message, "Provide a message" },
	{ LangCode::encrypt_decrypt, "Do you want to encrypt or decrypt?" },
	// ceasar's settings codes
	{ LangCode::set_offset, "Set offset" },
	{ LangCode::set_direction, "Set direction" },
	// four square's settings codes
	{ LangCode::set_keyword, "Set keyword" },
	// validation codes
	{ LangCode::v_max_length, "Cannot exceed max length, max length" },
	{ LangCode::v_not_empty, "Cannot be empty" },
	{ LangCode::v_allowed, "Input not allowed" },
	{ LangCode::v_not_0, "Cannot be 0" },
	{ LangCode::v_max_value, "Cannot be greater than" },
	{ LangCode::v_min_value, "Cannot be less than" },
};