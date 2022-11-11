#include <iostream>
#include <memory>
#include "EncryptionContext.h"
#include "CeasarCipher.h"

int main() {
	CeasarCipher ceasar(4);
	EncryptionContext context(std::make_unique<CeasarCipher>(ceasar));
	std::cout << context.encrypt_message("karolina") << '\n';
	std::cout << context.decrypt_message("karolina") << '\n';
}