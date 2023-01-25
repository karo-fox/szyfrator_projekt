#pragma once

#include "UserInterface.h"

/// <summary>
/// Allows communication with User Interface
/// </summary>
class Communicator {
protected:
	UserInterface& ui_;
public:
	Communicator(UserInterface& ui) : ui_{ ui } {};
};
