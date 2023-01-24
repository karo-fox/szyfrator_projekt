#include <map>
#include <utility>

#include "UserInterface.h"
#include "ciphers.h"
#include "CipherStrategy.h"
#include "CeasarCipher.h"

std::map<Cipher, CipherStrategy&> setup_ciphers() {
	std::map<Cipher, CipherStrategy&> ciphers{};
	CeasarCipher ceasar{};
	ciphers.insert(std::pair<Cipher, CeasarCipher&>(Cipher::ceasar, ceasar));
	return ciphers;
}