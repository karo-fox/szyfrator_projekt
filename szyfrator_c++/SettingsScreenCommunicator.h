#pragma once

#include <vector>
#include <string>

#include "ScreenCommunicator.h"
#include "settings.h"
#include "lang.h"

class SettingsScreenCommunicator : public ScreenCommunicator {
public:
	SettingsScreenCommunicator(UserInterface& ui) : ScreenCommunicator{
		ui,
		LangCode::settings_screen_actions,
		{ "language", "file", "back" },
	} {};

	/// <summary>
	/// Gets new UI language from user
	/// </summary>
	/// <returns>New language to be set</returns>
	Language get_language() const;

	LangCode get_save_to_file_code_() const;
};