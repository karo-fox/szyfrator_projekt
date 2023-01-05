#pragma once

#include "CipherCommunicator.h"
#include "ceasar.h"
#include "UserInterface.h"

class CeasarCommunicator : public CipherCommunicator {
private:
	/// <summary>
	/// Maximum offset for the CeasarCipher
	/// </summary>
	int max_offset_{ 26 };
public:
	CeasarCommunicator(const UserInterface& ui) : CipherCommunicator{ ui } {};

	/// <summary>
	/// Asks user for integer input to set the CeasarCipher offset
	/// </summary>
	/// <returns>Offset to be set</returns>
	int set_offset() const;

	/// <summary>
	/// Asks user for text input to set the CeasarCipher direction
	/// </summary>
	/// <returns>Direction to be set</returns>
	Direction set_direction() const;
};