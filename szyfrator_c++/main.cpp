#include <memory>
#include <map>

#include "setup.h"

#include "UserInterface.h"
#include "ConsoleUI.h"
#include "ScreenController.h"

#include "ciphers.h"
#include "EncryptionContext.h"
#include "CipherStrategy.h"
#include "CeasarCipher.h"

int main() {
	//const CLI ui{};
	//CeasarCipher ceasar{ ui };
	//ceasar.new_settings();
	//EncryptionContext context{std::make_unique<CeasarCipher>(ceasar)};
	//ui.show_text("Provide message: ");
	//std::string input = ui.text_input();
	//std::string e_message{ context.encrypt_message(input) };
	//ui.show_text(e_message);
	//std::string d_message{ context.decrypt_message(e_message) };
	//ui.show_text(d_message);


	// setup
	ConsoleUI ui{};
	EncryptionContext context{ std::make_unique<CeasarCipher>(CeasarCipher{ui}) }; // initialize with default cipher
	std::map<Cipher, CipherStrategy&> ciphers{ setup_ciphers(ui) };

	ScreenController controller{ ui };
	controller.start();

	//ciphers.find(Cipher::ceasar)->second.new_settings();

	// main menu: 1) encrypt / decrypt, 2) settings, 3) quit
	// encrypt / decrypt: () type message, () action, 1) choose cipher, 2) back
	// choose cipher: () new settings, 1) back, 2) main menu, - output
	// output: 1) main menu
	// settings: 1) change language, 2) save to file, 3) back
}