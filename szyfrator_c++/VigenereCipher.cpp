#include "VigenereCipher.h"
#include "UserInterface.h"
#include "CeasarCipher.h"
#include "CipherCommunicator.h"
#include "ceasar.h"

VigenereCipher::VigenereCipher() {
	VigenereCipher::reset_settings();
}

void VigenereCipher::reset_settings() {
	keyword_ = "";
	settings_ = false;
}

void VigenereCipher::new_settings(const CipherCommunicator& communicator) {
	keyword_ = communicator.set_keyword();
	direction_ = communicator.set_direction();
	settings_ = true;
}

std::string VigenereCipher::encrypt(const std::string& txt) {
	std::string result;
	std::string plaintext{ txt };
	while (keyword_.size() < plaintext.size()) {
		keyword_ += keyword_;
	}
	while (keyword_.size() != plaintext.size()) {
		keyword_.pop_back();
	}
	CeasarCipher ceasar{};
	ceasar.set_new_direction(VigenereCipher::direction_);
	for (int i{}; i < plaintext.size(); i++) {
		const std::string letter{ plaintext.at(i) };
		const char key{ keyword_.at(i) };
		int base{};
		if (key <= 90) {
			base = 65;
		}
		if (key >= 97) {
			base = 97;
		}
		if (direction_ == Direction::right) {
			ceasar.set_new_offset(key - base);
		}
		if (direction_ == Direction::left) {
			ceasar.set_new_offset(26 - (key - base));
		}
		result += ceasar.encrypt(letter);
	}
	return result;
}

std::string VigenereCipher::decrypt(const std::string& txt) {
	std::string result;
	std::string plaintext{ txt };
	while (keyword_.size() < plaintext.size()) {
		keyword_ += keyword_;
	}
	while (keyword_.size() != plaintext.size()) {
		keyword_.pop_back();
	}
	CeasarCipher ceasar{};
	ceasar.set_new_direction(VigenereCipher::direction_);
	for (int i{}; i < plaintext.size(); i++) {
		const std::string letter{ plaintext.at(i) };
		const char key{ keyword_.at(i) };
		int base{};
		if (key <= 90) {
			base = 65;
		}
		if (key >= 97) {
			base = 97;
		}
		if (direction_ == Direction::right) {
			ceasar.set_new_offset(key - base);
		}
		if (direction_ == Direction::left) {
			ceasar.set_new_offset(26 - (key - base));
		}
		result += ceasar.decrypt(letter);
	}
	return result;
}