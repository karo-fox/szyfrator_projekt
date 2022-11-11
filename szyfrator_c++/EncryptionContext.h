#pragma once

#include <memory>
#include "CipherStrategy.h"
class EncryptionContext {
private:
	// use move semantics so it can dynamically change cipher_
	std::unique_ptr<CipherStrategy> cipher_;

public:
	explicit EncryptionContext(std::unique_ptr<CipherStrategy> &&cipher);
	void set_cipher(std::unique_ptr<CipherStrategy> &&cipher);
	std::string encrypt_message(std::string message) const;
	std::string decrypt_message(std::string message) const;
};