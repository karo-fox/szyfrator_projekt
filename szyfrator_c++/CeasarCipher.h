#pragma once

#include <string>

#include "CipherStrategy.h"
#include "CipherCommunicator.h"
#include "ceasar.h"

/// <summary>
/// Encrypts text with ceasar cipher
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
	/// <summary>
	/// calls reset_settings() to populate settings with defaults
	/// </summary>
	CeasarCipher();

	/// <summary>
	/// Asks user for new cipher settings
	/// </summary>
	void new_settings(const CipherCommunicator& communicator) override;

	/// <summary>
	/// Resets the cipher settings to default
	/// </summary>
	void reset_settings() override;

	/// <summary>
	/// Encrypts specified text
	/// </summary>
	/// <param name="txt">Text to encrypt</param>
	/// <returns>Encrypted text</returns>
	std::string encrypt(const std::string& txt) override;

	/// <summary>
	/// Decrypts specified text
	/// </summary>
	/// <param name="txt">Text to decrypt</param>
	/// <returns>Decrypted text</returns>
	std::string decrypt(const std::string& txt) override;

	/// <summary>
	/// Sets new offset
	/// </summary>
	/// <param name="offset">New offset</param>
	void set_new_offset(int offset);

	/// <summary>
	/// Sets new direction
	/// </summary>
	/// <param name="direction">New direction</param>
	void set_new_direction(Direction direction);
};
