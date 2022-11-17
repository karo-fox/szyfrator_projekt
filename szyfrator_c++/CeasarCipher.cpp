#include <string>
#include "CeasarCipher.h"
#include "CeasarSetter.h"
#include "ceasar.h"

CeasarCipher::CeasarCipher(const CeasarSetter& setter) : setter_{ setter } {
	CeasarCipher::reset_settings();
}

void CeasarCipher::new_settings() {
	CeasarCipher::offset_ = setter_.set_offset();
	CeasarCipher::direction_ = setter_.set_direction();
	CeasarCipher::settings_ = true; // you should assert this somehow
}

void CeasarCipher::reset_settings() {
	CeasarCipher::offset_ = 0;
	CeasarCipher::direction_ = Direction::right;
	CeasarCipher::settings_ = false;
}


std::string CeasarCipher::encrypt(const std::string& txt) const {
	return "Inside CeasarCipher::encrypt: " + txt;
}

std::string CeasarCipher::decrypt(const std::string& txt) const {
	return "Inside CeasarCipher::decrypt: " + txt;
}
