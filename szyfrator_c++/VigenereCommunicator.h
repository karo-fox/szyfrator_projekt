#pragma once

#include <string>

#include "Communicator.h"
#include "UserInterface.h"
#include "ceasar.h"

class VigenereCommunicator : public Communicator {
public:
	VigenereCommunicator(UserInterface& ui) : Communicator{ ui } {};

	std::string set_keyword() const;

	Direction set_direction() const;
};