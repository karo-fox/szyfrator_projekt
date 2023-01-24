#pragma once

#include <string>
#include "CipherCommunicator.h"

/// <summary>
/// Abract class for ciphers
/// </summary>
class CipherStrategy {
public:
	/// <summary>
	/// Encrypts specified text
	/// </summary>
	/// <param name="txt">Text to encrypt</param>
	/// <returns>Encrypted text</returns>
	virtual std::string encrypt(const std::string& txt) = 0;

	/// <summary>
	/// Decrypts specified text
	/// </summary>
	/// <param name="txt">Text to decrypt</param>
	/// <returns>Decrypted text</returns>
	virtual std::string decrypt(const std::string& txt) = 0;

	/// <summary>
	/// Asks user for new cipher settings
	/// </summary>
	virtual void new_settings(const CipherCommunicator& communicator) = 0;

	/// <summary>
	/// Resets the cipher settings to default
	/// </summary>
	virtual void reset_settings() = 0;

	virtual ~CipherStrategy() = default;
};