#pragma once

#include <string>

#include "Communicator.h"
#include "four_square.h"
#include "UserInterface.h"

class FourSquareCommunicator : public Communicator {
private:
	int max_length_{ 25 };
public:
	FourSquareCommunicator(UserInterface& ui) : Communicator{ ui } {};

	std::string set_keyword() const;
};