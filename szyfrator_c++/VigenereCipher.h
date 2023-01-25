#pragma once

#include <string>

#include "CipherStrategy.h"
#include "CipherCommunicator.h"
#include "ceasar.h"

/// <summary>
/// Encrypts a text with Vigenere's cipher
/// </summary>
class VigenereCipher : public CipherStrategy {
private:
	/// <summary>
	/// Keyword, a base for Ceasar's offsets during encryption
	/// </summary>
	std::string keyword_;

	/// <summary>
	/// Specifies in which direction the offset will go
	/// </summary>
	Direction direction_;

	/// <summary>
	/// true if settings are different from default
	/// </summary>
	bool settings_;
public:
	/// <summary>
	/// calls reset_settings() to populate settings with defaults
	/// </summary>
	VigenereCipher();

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
};
