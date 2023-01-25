#pragma once

#include <map>
#include <string>
#include <vector>
#include <set>

#include "CipherStrategy.h"
#include "four_square.h"
#include "CipherCommunicator.h"

/// <summary>
/// Encrypts a text with four-square cipher
/// </summary>
class FourSquareCipher : public CipherStrategy {
private:
	/// <summary>
	/// First keyword, populates the top-right matrix
	/// </summary>
	std::string keyword1_;
	
	/// <summary>
	/// Second keyword, populates the bottom-left matrix
	/// </summary>
	std::string keyword2_;

	/// <summary>
	/// A map of letter matrices used for encryption
	/// </summary>
	std::map<SquareCode, SquareMatrix> squares_;

	/// <summary>
	/// Contains characters removed from the plaintext
	/// </summary>
	std::vector<Redundant> removed_;

	/// <summary>
	/// The characters that will be removed from plaintext
	/// </summary>
	std::set<std::string> to_remove_{ " ", "q" };

	/// <summary>
	/// true if settings are different from default
	/// </summary>
	bool settings_;

	/// <summary>
	/// Removes characters specified in to_remove_ set from the string
	/// and saves them into removed_ vector
	/// </summary>
	/// <param name="str">string to remove characters from</param>
	/// <returns>string with redundant characters removed</returns>
	std::string remove_redundant_(const std::string& str);

	/// <summary>
	/// Inserts redundant characters saved in removed_ vector
	/// back into the string
	/// </summary>
	/// <param name="str">string to insert characters back into</param>
	/// <returns>string with redundant characters inserted back</returns>
	std::string insert_redundant_(const std::string& str);
public:
	/// <summary>
	/// calls reset_settings() to populate settings with defaults
	/// </summary>
	FourSquareCipher();

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
