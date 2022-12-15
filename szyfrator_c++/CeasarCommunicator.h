#pragma once

#include "CipherCommunicator.h"
#include "ceasar.h"
#include "UserInterface.h"

class CeasarCommunicator : public CipherCommunicator {
private:
	int max_offset_{ 26 };
public:
	CeasarCommunicator(const UserInterface& ui) : CipherCommunicator{ ui } {};
	int set_offset() const;
	Direction set_direction() const;
	void choose_alphabet(Alphabet alphabet);
};