#include <string>

#include "screens.h"
#include "MainScreen.h"
#include "lang.h"

#include "ciphers.h"
#include "CeasarCipher.h"

ScreenType MainScreen::run() const {
	communicator_.show_title(ui_.parse(LangCode::main_title));
	while (true) {
		communicator_.show_actions();
		std::string input = communicator_.get_action();
		if (input == "start") {
			start_encryption();
			return ScreenType::stay;
		}
		else if (input == "quit") {
			exit(0);
			return ScreenType::stay;
		}
		else if (change_screen_.contains(input)) {
			return change_screen_.at(input);
		}
		else {
			communicator_.action_not_found();
		}
	}
}

void MainScreen::start_encryption() const {
	CipherAction action = communicator_.get_cipher_action();
	std::string message = communicator_.get_message();
	Cipher cipher_code = communicator_.get_cipher();
	std::string output{};
	provide_cipher(cipher_code);
	if (action == CipherAction::encrypt) {
		output = context_.encrypt_message(message);
	}
	else if (action == CipherAction::decrypt) {
		output = context_.decrypt_message(message);
	}
	communicator_.show_output(output);
}

void MainScreen::provide_cipher(Cipher cipher_code) const {
	switch (cipher_code) {
	case Cipher::ceasar:
		context_.set_cipher(std::make_unique<CeasarCipher>(CeasarCipher{ ui_ }));
		return;
	}
}