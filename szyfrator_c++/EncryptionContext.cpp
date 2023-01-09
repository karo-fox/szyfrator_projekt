#include <memory>
#include "EncryptionContext.h"

void EncryptionContext::set_cipher(std::unique_ptr<CipherStrategy> &&cipher) {
	active_cipher_ = std::move(cipher);
}

std::string EncryptionContext::encrypt_message(const std::string& message) const {
	active_cipher_.get()->new_settings();
	return active_cipher_->encrypt(message);
}

std::string EncryptionContext::decrypt_message(const std::string& message) const {
	active_cipher_.get()->new_settings();
	return active_cipher_->decrypt(message);
}