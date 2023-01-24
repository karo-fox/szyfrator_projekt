#pragma once

#include <string>
#include "CipherStrategy.h"
#include "UserInterface.h"
#include "CipherCommunicator.h"
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
	/// Checks if the replacing letter does not exceed alphabet range
	/// </summary>
	/// <param name="letter">Replacing letter</param>
	/// <returns>True if letter does not exceed range</returns>
	bool is_in_(char letter) const;

	/// <summary>
	/// Checks if the replacing letter does exceed alphabet range
	/// </summary>
	/// <param name="letter">Replacing letter</param>
	/// <returns>True if letter does exceed range</returns>
	bool is_out_(char letter) const;

public:
	CeasarCipher();
	void new_settings(const CipherCommunicator& communicator) override;
	void reset_settings() override;
	std::string encrypt(const std::string& txt) override;
	std::string decrypt(const std::string& txt) override;

	void set_new_offset(int offset);
	void set_new_direction(Direction direction);
};