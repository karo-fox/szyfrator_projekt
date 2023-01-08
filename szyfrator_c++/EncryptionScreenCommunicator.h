#pragma once

#include <string>
#include <vector>

#include "ScreenCommunicator.h"
#include "UserInterface.h"
#include "lang.h"

class EncryptionScreenCommunicator : public ScreenCommunicator {
public:
	EncryptionScreenCommunicator(UserInterface& ui) : ScreenCommunicator{ 
		ui,
		LangCode::encryption_screen_actions,
		{ "start", "back" }
	} {};
};