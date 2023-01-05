#pragma once

#include "screens.h"
#include "UserInterface.h"

/// <summary>
/// Manages actions connected with encrypting and decrypting messages
/// </summary>
class EncryptionScreen : public Screen {
public:
	EncryptionScreen(const UserInterface& ui) : Screen{ ui } {};
	/// <summary>
	/// Presents some actions for user to take:
	/// - encrypt or decrypt a message
	/// - go back
	/// </summary>
	/// <returns></returns>
	ScreenType run() const override;
};