#include <string>
#include <memory>

#include "screens.h"
#include "MainScreen.h"
#include "lang.h"

#include "ciphers.h"
#include "CeasarCipher.h"
#include "FourSquareCipher.h"
#include "VigenereCipher.h"
#include "RailFenceCipher.h"

ScreenType MainScreen::run() const {
	communicator_.show_title(ui_.parse(LangCode::main_title));
	while (true) {
		communicator_.show_actions();
		std::string input = communicator_.get_action();
		if (input == "start") {
			std::string result{ start_encryption() };
			communicator_.show_output(result);
			if (ui_.settings_.save_to_file_) {
				file_manager_.save_to_file_(result);
				communicator_.show_save_to_file();
			}
			communicator_.wait();
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

std::string MainScreen::start_encryption() const {
	CipherAction action = communicator_.get_cipher_action();
	std::string message = communicator_.get_message();
	Cipher cipher_code = communicator_.get_cipher();
	std::string output{};
	provide_cipher_(cipher_code);
	if (action == CipherAction::encrypt) {
		output = context_.encrypt_message(message);
	}
	else if (action == CipherAction::decrypt) {
		output = context_.decrypt_message(message);
	}
	return output;
}

void MainScreen::provide_cipher_(Cipher cipher_code) const {
	switch (cipher_code) {
	case Cipher::ceasar:
		context_.set_cipher(std::make_unique<CeasarCipher>(CeasarCipher{}));
		return;
	case Cipher::four_square:
		context_.set_cipher(std::make_unique<FourSquareCipher>(FourSquareCipher{}));
		return;
	case Cipher::vigenere:
		context_.set_cipher(std::make_unique<VigenereCipher>(VigenereCipher{}));
		return;
	case Cipher::rail_fence:
		context_.set_cipher(std::make_unique<RailFenceCipher>(RailFenceCipher{}));
		return;
	}
}
