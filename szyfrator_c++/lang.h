#pragma once

#include <map>
#include <string>

enum LangCode {
	yes, no,
	current_language,
	menu_title,
	encryption_title,
	settings_title,
	show_language,
	save_to_file,
	choose_language,
	menu_screen_actions,
	encryption_screen_actions,
	settings_screen_actions,
	available_actions,
	choose_action,
	action_not_found,
	set_offset,
	set_direction,
	invalid_input,
	v_max_length,
	v_not_empty,
	v_allowed,
	v_not_0,
	v_max_value,
	v_min_value,
};

enum Language {
	en, pl
};

typedef std::map<LangCode, std::string> locale;
typedef std::map<Language, locale> langMap;