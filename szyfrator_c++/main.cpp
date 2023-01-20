#include <memory>
#include <map>

#include "setup.h"

#include "FileManager.h"

#include "UserInterface.h"
#include "ConsoleUI.h"
#include "ScreenController.h"

#include "ciphers.h"
#include "EncryptionContext.h"
#include "CipherStrategy.h"
#include "CeasarCipher.h"

int main() {
	ConsoleUI ui{};
	std::map<Cipher, CipherStrategy&> ciphers{ setup_ciphers(ui) };
	EncryptionContext context{ std::make_unique<CeasarCipher>(CeasarCipher{ui}) }; // initialize with default cipher

	const FileManager file_manager{};

	ScreenController controller{ ui, context, file_manager };
	controller.start();
}