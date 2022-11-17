#pragma once

#include <memory>
#include "CipherStrategy.h"

class EncryptionContext {
private:
	// use move semantics so it can dynamically change cipher_
	std::unique_ptr<CipherStrategy> cipher_;

public:
	EncryptionContext(std::unique_ptr<CipherStrategy> &&cipher);
	void set_cipher(std::unique_ptr<CipherStrategy> &&cipher);
	std::string encrypt_message(const std::string& message) const;
	std::string decrypt_message(const std::string& message) const;
};