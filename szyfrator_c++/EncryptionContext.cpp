#include <memory>
#include "EncryptionContext.h"

EncryptionContext::EncryptionContext(std::unique_ptr<CipherStrategy> &&cipher)
	: active_cipher_{std::move(cipher)} {
}

void EncryptionContext::set_cipher(std::unique_ptr<CipherStrategy> &&cipher) {
	active_cipher_ = std::move(cipher);
}

std::string EncryptionContext::encrypt_message(const std::string& message) const {
	return active_cipher_->encrypt(message);
}

std::string EncryptionContext::decrypt_message(const std::string& message) const {
	return active_cipher_->decrypt(message);
}