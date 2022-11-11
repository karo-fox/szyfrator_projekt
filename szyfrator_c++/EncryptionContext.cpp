#include <memory>
#include "EncryptionContext.h"

EncryptionContext::EncryptionContext(std::unique_ptr<CipherStrategy> &&cipher)
	: cipher_{std::move(cipher)} {
}

void EncryptionContext::set_cipher(std::unique_ptr<CipherStrategy> &&cipher) {
	EncryptionContext::cipher_ = std::move(cipher);
}

std::string EncryptionContext::encrypt_message(std::string message) const {
	return EncryptionContext::cipher_->encrypt(message);
}

std::string EncryptionContext::decrypt_message(std::string message) const {
	return EncryptionContext::cipher_->decrypt(message);
}