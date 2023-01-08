#pragma once

#include <vector>
#include <string>

#include "ScreenCommunicator.h"
#include "lang.h"

class MenuScreenCommunicator : public ScreenCommunicator {
public:
	MenuScreenCommunicator(UserInterface& ui) : ScreenCommunicator{ 
		ui, 
		LangCode::menu_screen_actions, 
		{ "settings", "encryption", "quit"} 
	} {};
};