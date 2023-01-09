#pragma once

#include <string>
#include <vector>

#include "ScreenCommunicator.h"
#include "UserInterface.h"
#include "lang.h"
#include "ciphers.h"

class EncryptionScreenCommunicator : public ScreenCommunicator {
public:
	EncryptionScreenCommunicator(UserInterface& ui) : ScreenCommunicator{ 
		ui,
		LangCode::encryption_screen_actions,
		{ "start", "back" }
	} {};

	CipherAction get_cipher_action() const;

	std::string get_message() const;

	Cipher get_cipher() const;

	void show_output(const std::string& output) const;
};