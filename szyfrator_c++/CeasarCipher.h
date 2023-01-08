#pragma once

#include <string>
#include "CipherStrategy.h"
#include "UserInterface.h"
#include "CeasarCommunicator.h"
#include "ceasar.h"

/// <summary>
/// Encrypts text with ceasar cipher
/// Each letter is replaced with another letter,
/// which is set number of positions away in the set direction in the alphabet
/// If set offset will exceed the length of the alphabet, it will continue from 
/// beginning or the end (according to the set direction)
/// </summary>
class CeasarCipher : public CipherStrategy {
private:
	/// <summary>
	/// Specifies how many positions away in the alphabet is the replacing letter
	/// </summary>
	int offset_;

	/// <summary>
	/// Specifies in which direction the offset will go
	/// </summary>
	Direction direction_;

	/// <summary>
	/// true if settings are different from default
	/// </summary>
	bool settings_;

	/// <summary>
	/// Communicator responsible for getting settings from user
	/// </summary>
	const CeasarCommunicator communicator_;


	/// <summary>
	/// Checks if the replacing letter does not exceed alphabet range
	/// </summary>
	/// <param name="letter">Replacing letter</param>
	/// <returns>True if letter does not exceed range</returns>
	bool is_in(char letter) const;

	/// <summary>
	/// Checks if the replacing letter does exceed alphabet range
	/// </summary>
	/// <param name="letter">Replacing letter</param>
	/// <returns>True if letter does exceed range</returns>
	bool is_out(char letter) const;

public:
	CeasarCipher(UserInterface& ui);
	void new_settings() override;
	void reset_settings() override;
	std::string encrypt(const std::string& txt) override;
	std::string decrypt(const std::string& txt) override;
};