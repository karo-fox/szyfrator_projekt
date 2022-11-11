#include <string>
#include "CeasarCipher.h"

CeasarCipher::CeasarCipher(int offset, Direction direction)
	: offset_{ offset }, direction_ {direction} {
};

std::string CeasarCipher::encrypt(std::string& txt) const {
	return "Inside CeasarCipher::encrypt: " + txt;
}

std::string CeasarCipher::decrypt(std::string& txt) const {
	return "Inside CeasarCipher::decrypt: " + txt;
}