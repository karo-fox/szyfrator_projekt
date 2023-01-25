#include <string>

#include "MainScreenCommunicator.h"
#include "ciphers.h"
#include "validators.h"
#include "ValidationException.h"
#include "lang.h"

CipherAction MainScreenCommunicator::get_cipher_action() const {
    while (true) {
        ui_.show_text(ui_.parse(LangCode::encrypt_decrypt) + " [encrypt/decrypt]:");
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
            ui_.show_text(ui_.parse(e.msg_code_, e.validation_args_));
        }
    }
}

std::string MainScreenCommunicator::get_message() const {
    while (true) {
        ui_.show_text(ui_.parse(LangCode::provide_message) + ": ");
        std::string input = ui_.text_input();
        try {
            validate_not_empty(input);
            validate_max_length(input, 100);
            return input;
        }
        catch (const ValidationException<std::string>& e) {
            ui_.show_text(ui_.parse(e.msg_code_, e.validation_args_));
        }
   }
}

Cipher MainScreenCommunicator::get_cipher() const {
    while (true) {
        ui_.show_text(ui_.parse(LangCode::choose_cipher));
        ui_.show_text(ui_.parse(LangCode::available_ciphers));
        std::string input = ui_.text_input();
        try {
            validate_not_empty(input);
            validate_allowed(
                input, { "ceasar", "four square", "vigenere", "rail fence"}
            );
            if (input == "ceasar") {
                return Cipher::ceasar;
            }
            else if (input == "four square") {
                return Cipher::four_square;
            }
            else if (input == "vigenere") {
                return Cipher::vigenere;
            }
            else if (input == "rail fence") {
                return Cipher::rail_fence;
            }
        }
        catch (const ValidationException<std::string>& e) {
            ui_.show_text(ui_.parse(e.msg_code_, e.validation_args_));
        }
    }
}

void MainScreenCommunicator::show_output(const std::string& output) const {
    try {
        validate_not_empty(output);
        ui_.show_text(ui_.parse(LangCode::result) + ": ");
        ui_.show_text(output);
    }
    catch (const ValidationException<std::string>& e) {
        ui_.show_text(ui_.parse(e.msg_code_, e.validation_args_));
    }
    
}

void MainScreenCommunicator::show_save_to_file() const {
    ui_.show_text(ui_.parse(LangCode::file_saved));
}

void MainScreenCommunicator::wait() const {
    ui_.show_text(ui_.parse(LangCode::key_continue) + ": ");
    ui_.text_input();
}