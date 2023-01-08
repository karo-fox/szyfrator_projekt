#include <map>
#include <utility>

#include "UserInterface.h"
#include "ciphers.h"
#include "CipherStrategy.h"
#include "CeasarCipher.h"

std::map<Cipher, CipherStrategy&> setup_ciphers(const UserInterface& ui) {
	std::map<Cipher, CipherStrategy&> ciphers{};
	CeasarCipher ceasar{ ui };
	ciphers.insert(std::pair<Cipher, CeasarCipher&>(Cipher::ceasar, ceasar));
	return ciphers;
}