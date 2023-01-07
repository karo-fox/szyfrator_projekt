#include <string>
#include "CeasarCipher.h"
#include "UserInterface.h"
#include "CeasarCommunicator.h"
#include "ceasar.h"

CeasarCipher::CeasarCipher(UserInterface& ui)
	: communicator_{ ui } {
	reset_settings();
}

void CeasarCipher::new_settings() {
	offset_ = communicator_.set_offset();
	direction_ = communicator_.set_direction();
	settings_ = true; // you should assert this somehow
}

void CeasarCipher::reset_settings() {
	offset_ = 0;
	direction_ = Direction::right;
	settings_ = false;
}


std::string CeasarCipher::encrypt(const std::string& txt) {
	std::string result{};
	for (char letter : txt) {
		if (is_in(letter)) {
			char new_letter = letter + offset_ * direction_;
			result.push_back(new_letter);
		}
		else if (is_out(letter)) {
			char new_letter = letter + (offset_ - 26) * direction_;
			result.push_back(new_letter);
		}
		else {
			result.push_back(letter);
		}
	}
	return result;
}

std::string CeasarCipher::decrypt(const std::string& txt) {
	offset_ = 26 - offset_;
	return encrypt(txt);
}

bool CeasarCipher::is_in(char letter) const {
	if (direction_ == Direction::right) {
		return (letter >= 65 && letter <= 90 - offset_)
			|| (letter >= 97 && letter <= 122 - offset_);
	}
	else if (direction_ == Direction::left) {
		return (letter >= 65 + offset_ && letter <= 90)
			|| (letter >= 97 + offset_ && letter <= 122);
	}
}

bool CeasarCipher::is_out(char letter) const {
	if (direction_ == Direction::right) {
		return (letter > 90 - offset_ && letter <= 90)
			|| (letter > 122 - offset_ && letter <= 122);
	}
	else if (direction_ == Direction::left) {
		return (letter >= 65 && letter < 65 + offset_)
			|| (letter >= 97 && letter < 97 + offset_);
	}
}


