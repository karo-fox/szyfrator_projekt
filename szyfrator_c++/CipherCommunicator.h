#pragma once

#include "UserInterface.h"

class CipherCommunicator {
protected:
	const UserInterface& ui_;
public:
	CipherCommunicator(const UserInterface& ui) : ui_{ ui } {};
};