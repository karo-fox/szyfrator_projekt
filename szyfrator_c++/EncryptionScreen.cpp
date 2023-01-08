#include <string>
#include <memory>

#include "EncryptionScreen.h"
#include "screens.h"
#include "lang.h"
#include "ciphers.h"
#include "CeasarCipher.h"

ScreenType EncryptionScreen::run() const {
	communicator_.show_title(ui_.parse(LangCode::encryption_title));
	while (true) {
		communicator_.show_actions();
		std::string input = communicator_.get_action();
		if (input == "start") {
			CipherAction action = communicator_.get_cipher_action();
			std::string message = communicator_.get_message();
			Cipher cipher_code = communicator_.get_cipher();
			if (cipher_code == Cipher::ceasar) {
				CeasarCipher cipher{ ui_ };
				context_.set_cipher(std::make_unique<CeasarCipher>(cipher));
			}
			if (action == CipherAction::encrypt) {
				context_.encrypt_message(message);
			}
			else if (action == CipherAction::decrypt) {
				context_.decrypt_message(message);
			}
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