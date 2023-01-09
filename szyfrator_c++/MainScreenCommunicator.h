#pragma once

#include <vector>
#include <string>

#include "ScreenCommunicator.h"
#include "lang.h"
#include "ciphers.h"

class MainScreenCommunicator : public ScreenCommunicator {
public:
	MainScreenCommunicator(UserInterface& ui) : ScreenCommunicator{ 
		ui, 
		LangCode::main_screen_actions, 
		{ "settings", "encryption", "quit", "start"}
	} {};

	CipherAction get_cipher_action() const;

	std::string get_message() const;

	Cipher get_cipher() const;

	void show_output(const std::string& output) const;
};