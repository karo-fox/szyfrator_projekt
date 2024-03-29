#include <string>
#include <cassert>

#include "CeasarCipher.h"
#include "UserInterface.h"
#include "CipherCommunicator.h"
#include "ceasar.h"

CeasarCipher::CeasarCipher() {
	CeasarCipher::reset_settings();
}

void CeasarCipher::new_settings(const CipherCommunicator& communicator) {
	CeasarCipher::offset_ = communicator.set_offset();
	CeasarCipher::direction_ = communicator.set_direction();
	CeasarCipher::settings_ = true; // you should assert this somehow
}

void CeasarCipher::reset_settings() {
	CeasarCipher::offset_ = 0;
	CeasarCipher::direction_ = Direction::right;
	CeasarCipher::settings_ = false;
}


std::string CeasarCipher::encrypt(const std::string& txt) {
	std::string result{};
	for (char letter : txt) {
		if (CeasarCipher::is_in_(letter)) {
			char new_letter = 
				letter + CeasarCipher::offset_ * static_cast<int>(CeasarCipher::direction_);
			result.push_back(new_letter);
		}
		else if (CeasarCipher::is_out_(letter)) {
			char new_letter = letter + 
				(CeasarCipher::offset_ - 26) * static_cast<int>(CeasarCipher::direction_);
			result.push_back(new_letter);
		}
		else {
			result.push_back(letter);
		}
	}
	return result;
}

std::string CeasarCipher::decrypt(const std::string& txt) {
	CeasarCipher::offset_ = 26 - CeasarCipher::offset_;
	return CeasarCipher::encrypt(txt);
}

bool CeasarCipher::is_in_(char letter) const {
	if (CeasarCipher::direction_ == Direction::right) {
		return (letter >= 65 && letter <= 90 - CeasarCipher::offset_)
			|| (letter >= 97 && letter <= 122 - CeasarCipher::offset_);
	}
	else if (CeasarCipher::direction_ == Direction::left) {
		return (letter >= 65 + CeasarCipher::offset_ && letter <= 90)
			|| (letter >= 97 + CeasarCipher::offset_ && letter <= 122);
	}
}

bool CeasarCipher::is_out_(char letter) const {
	if (CeasarCipher::direction_ == Direction::right) {
		return (letter > 90 - CeasarCipher::offset_ && letter <= 90)
			|| (letter > 122 - CeasarCipher::offset_ && letter <= 122);
	}
	else if (CeasarCipher::direction_ == Direction::left) {
		return (letter >= 65 && letter < 65 + CeasarCipher::offset_)
			|| (letter >= 97 && letter < 97 + CeasarCipher::offset_);
	}
}


void CeasarCipher::set_new_offset(int offset) {
	assert(offset >= 0);
	assert(offset <= 26);
	CeasarCipher::offset_ = offset;
}

void CeasarCipher::set_new_direction(Direction direction) {
	CeasarCipher::direction_ = direction;
}
