#pragma once

#include <string>
#include <set>

#include "CipherStrategy.h"
#include "CipherCommunicator.h"

/// <summary>
/// Encrypts a text with rail fence cipher
/// </summary>
class RailFenceCipher : public CipherStrategy {
private:
	/// <summary>
	/// Number of rails
	/// </summary>
	int rails_;

	/// <summary>
	/// true if settings are different from default
	/// </summary>
	bool settings_;

	/// <summary>
	/// Set of letters that will be removed from plaintext
	/// </summary>
	std::set<std::string> to_remove_{ " ", ".", ",", "!", "?" };

	/// <summary>
	/// Removes characters specified in to_remove_ set from string
	/// </summary>
	/// <param name="str">string to remove characters from</param>
	/// <returns>stirng with redundant characters removed</returns>
	std::string remove_redundant_(const std::string& str);
public:
	/// <summary>
	/// calls reset_settings() to populate settings with defaults
	/// </summary>
	RailFenceCipher();

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
