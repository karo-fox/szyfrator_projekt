#pragma once

#include "Communicator.h"
#include "UserInterface.h"
#include "ceasar.h"

/// <summary>
/// Manages interactions between ciphers and user interface
/// </summary>
class CipherCommunicator : public Communicator {
public:
	CipherCommunicator(UserInterface& ui) : Communicator{ ui } {};

	/// <summary>
	/// Asks user for input to specify the offset
	/// </summary>
	/// <returns>Offset to be set</returns>
	int set_offset() const;

	/// <summary>
	/// Asks user for input to specify the number of rails
	/// </summary>
	/// <returns>The number of rails to be set</returns>
	int set_rails() const;

	/// <summary>
	/// Asks user for input to specify the direction
	/// </summary>
	/// <returns>The direction to be set</returns>
	Direction set_direction() const;

	/// <summary>
	/// Asks user for inpur to specify the keyword
	/// </summary>
	/// <returns>The keyword to be set</returns>
	std::string set_keyword() const;
};
