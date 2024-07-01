#pragma once

#include <vector>
#include <string>

#include "ScreenCommunicator.h"
#include "lang.h"
#include "ciphers.h"

/// <summary>
/// Communicator for MainScreen
/// </summary>
class MainScreenCommunicator : public ScreenCommunicator {
public:
	MainScreenCommunicator(UserInterface& ui) : ScreenCommunicator{ 
		ui, 
		LangCode::main_screen_actions, 
		{ "settings", "encryption", "quit", "start"}
	} {};

	/// <summary>
	/// Asks user for input to set the action
	/// </summary>
	/// <returns>Action to be set</returns>
	CipherAction get_cipher_action() const;

	/// <summary>
	/// Asks user for message to encrypt or decrypt
	/// </summary>
	/// <returns>The message</returns>
	std::string get_message() const;

	/// <summary>
	/// Asks user for input to set the cipher
	/// </summary>
	/// <returns>Cipher to be set</returns>
	Cipher get_cipher() const;

	/// <summary>
	/// Present the result of encryption/decryption to user
	/// </summary>
	/// <param name="output">The result of encryption/decryption</param>
	void show_output(const std::string& output) const;

	/// <summary>
	/// Saves the result of encryption/decryption to file
	/// </summary>
	void show_save_to_file() const;

	/// <summary>
	/// Asks the user to take action to continue the program run
	/// </summary>
	void wait() const;
};
