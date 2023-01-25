#pragma once

#include <memory>

#include "CipherStrategy.h"
#include "CipherCommunicator.h"

/// <summary>
/// Stores currently active cipher
/// </summary>
class EncryptionContext {
private:
	// use move semantics so it can dynamically change active_cipher_
	std::unique_ptr<CipherStrategy> active_cipher_;

	const CipherCommunicator communicator_;
public:
	EncryptionContext(
		std::unique_ptr<CipherStrategy> &&cipher, 
		const CipherCommunicator communicator
	) : 
		active_cipher_{ std::move(cipher) }, 
		communicator_{ communicator }
	{};

	/// <summary>
	/// Sets new active cipher
	/// </summary>
	/// <param name="cipher">Cipher to be set</param>
	void set_cipher(std::unique_ptr<CipherStrategy> &&cipher);

	/// <summary>
	/// Runs `encrypt` method on active cipher
	/// </summary>
	/// <param name="message">Text to encrypt</param>
	/// <returns>Encrypted message</returns>
	std::string encrypt_message(const std::string& message) const;

	/// <summary>
	/// Runs `decrypt` method on active cipher
	/// </summary>
	/// <param name="message">Text to decrypt</param>
	/// <returns>Derypted message</returns>
	std::string decrypt_message(const std::string& message) const;
};
