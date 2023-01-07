#pragma once

#include "UserInterface.h"

/// <summary>
/// Allows communication with User Interface
/// </summary>
class Communicator {
protected:
	const UserInterface& ui_;
public:
	Communicator(const UserInterface& ui) : ui_{ ui } {};
};