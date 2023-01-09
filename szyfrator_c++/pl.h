#pragma once

#include <map>
#include <string>

#include "lang.h"

std::map<LangCode, std::string> polish{
	{ LangCode::yes, "tak" },
	{ LangCode::no, "nie" },
	{ LangCode::current_language, "Polski" },
	{ LangCode::main_title, "" },
	{ LangCode::encryption_title, "" },
	{ LangCode::settings_title, "" },
	{ LangCode::show_language, "" },
	{ LangCode::save_to_file, "" },
	{ LangCode::choose_language, "" },
	{ LangCode::main_screen_actions, "" },
	{ LangCode::encryption_screen_actions, "" },
	{ LangCode::settings_screen_actions, "" },
	{ LangCode::available_actions, "" },
	{ LangCode::choose_action, "" },
	{ LangCode::action_not_found, "" },
	{ LangCode::set_offset, "" },
	{ LangCode::set_direction, "" },
	{ LangCode::invalid_input, "" },
	{ LangCode::v_max_length, "" },
	{ LangCode::v_not_empty, "" },
	{ LangCode::v_allowed, "" },
	{ LangCode::v_not_0, "" },
	{ LangCode::v_max_value, "" },
	{ LangCode::v_min_value, "" },
};
