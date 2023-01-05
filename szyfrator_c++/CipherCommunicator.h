#pragma once

#include "UserInterface.h"

/// <summary>
/// Allows Cipher communication with User Interface to set the cipher settings
/// </summary>
class CipherCommunicator {
protected:
	const UserInterface& ui_;
public:
	CipherCommunicator(const UserInterface& ui) : ui_{ ui } {};
};