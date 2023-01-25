#pragma once

#include "Communicator.h"
#include "UserInterface.h"
#include "ceasar.h"

class CipherCommunicator : public Communicator {
public:
	CipherCommunicator(UserInterface& ui) : Communicator{ ui } {};

	int set_offset() const;
	int set_rails() const;
	Direction set_direction() const;
	std::string set_keyword() const;
};