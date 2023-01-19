#pragma once

#include <map>
#include <string>

enum class LangCode {
	// general codes
	yes, no,
	current_language,
	invalid_input,
	key_continue,
	// screen titles codes
	main_title,
	settings_title,
	// settings screen codes
	show_language,
	save_to_file,
	choose_language,
	// screen actions codes
	main_screen_actions,
	settings_screen_actions,
	available_screen_actions,
	choose_screen_action,
	action_not_found,
	// ciphers choice codess
	choose_cipher,
	available_ciphers,
	// other encryption codes
	provide_message,
	encrypt_decrypt,
	result,
	// ceasar's settings codes
	set_offset,
	set_direction,
	// validation codes
	v_max_length,
	v_not_empty,
	v_allowed,
	v_not_0,
	v_max_value,
	v_min_value,
};

enum class Language {
	en, pl
};

typedef std::map<LangCode, std::string> locale;
typedef std::map<Language, locale> langMap;