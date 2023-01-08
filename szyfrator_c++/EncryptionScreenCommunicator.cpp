#include <string>

#include "EncryptionScreenCommunicator.h"
#include "ciphers.h"
#include "validators.h"
#include "ValidationException.h"

CipherAction EncryptionScreenCommunicator::get_cipher_action() const {
    while (true) {
        ui_.show_text("Do you want to encrypt or decrypt?");
        std::string input = ui_.text_input();
        try {
            validate_not_empty(input);
            validate_allowed(input, { "decrypt", "encrypt" });
            if (input == "encrypt") {
                return CipherAction::encrypt;
            }
            else if (input == "decrypt") {
                return CipherAction::decrypt;
            }
        }
        catch (const ValidationException<std::string>& e) {
            ui_.show_text(e.what());
        }
    }
}

std::string EncryptionScreenCommunicator::get_message() const {
    while (true) {
        ui_.show_text("Provide a message:");
        std::string input = ui_.text_input();
        try {
            validate_not_empty(input);
            validate_max_length(input, 100);
            return input;
        }
        catch (const ValidationException<std::string>& e) {
            ui_.show_text(e.what());
        }
   }
}

Cipher EncryptionScreenCommunicator::get_cipher() const {
    while (true) {
        ui_.show_text("Choose one of the following ciphers:\nceasar");
        std::string input = ui_.text_input();
        try {
            validate_not_empty(input);
            validate_allowed(input, { "ceasar" });
            if (input == "ceasar") {
                return Cipher::ceasar;
            }
        }
        catch (const ValidationException<std::string>& e) {
            ui_.show_text(e.what());
        }
    }
}
