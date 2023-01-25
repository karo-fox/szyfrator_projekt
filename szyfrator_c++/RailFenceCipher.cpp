#include <string>

#include "RailFenceCipher.h"
#include "CipherCommunicator.h"
#include "Exception.h"
#include "utils.h"

RailFenceCipher::RailFenceCipher() {
	RailFenceCipher::reset_settings();
}

void RailFenceCipher::reset_settings() {
	rails_ = 0;
	settings_ = false;
}

void RailFenceCipher::new_settings(const CipherCommunicator& communicator) {
	rails_ = communicator.set_rails();
	settings_ = true;
}

std::string RailFenceCipher::encrypt(const std::string& txt) {
	std::string plaintext{ RailFenceCipher::remove_redundant_(txt) };
	std::vector<std::string> ciphertext(rails_, "");
	int idx{};
	while (idx < plaintext.size()) {
		try {
			for (int i{}; i < rails_ - 1; i++) {
				ciphertext.at(i) += plaintext.at(idx);
				idx++;
				if (idx >= plaintext.size()) {
					throw Exception{ "Possible out of range" };
				}
			}
			for (int i{ rails_ - 1 }; i > 0; i--) {
				ciphertext.at(i) += plaintext.at(idx);
				idx++;
				if (idx >= plaintext.size()) {
					throw Exception{ "Possible out of range" };
				}
			}
		}
		catch (const Exception& e) {
			break;
		}
	}
	std::string result;
	for (auto& elem : ciphertext) {
		result += elem + ' ';
	}
	return result;
}

std::string RailFenceCipher::decrypt(const std::string& txt) {
	std::vector<std::string> ciphertext{ split_str(txt, ' ') };
	std::string result;
	while (!vec_is_empty(ciphertext)) {
		try {
			for (int i{}; i < rails_ - 1; i++) {
				result += ciphertext.at(i).front();
				ciphertext.at(i).erase(0, 1);
				if (vec_is_empty(ciphertext)) {
					throw Exception{ "Possible empty vector" };
				}
			}
			for (int i{ rails_ - 1 }; i > 0; i--) {
				result += ciphertext.at(i).front();
				ciphertext.at(i).erase(0, 1);
				if (vec_is_empty(ciphertext)) {
					throw Exception{ "Possible empty vector" };
				}
			}
		}
		catch (const Exception& e) {
			break;
		}	
	}
	return result;
}

std::string RailFenceCipher::remove_redundant_(const std::string& str) {
	std::string result;
	for (int i{}; i < str.size(); i++) {
		if (!redundant_.contains(std::string{ str.at(i) })) {
			result.push_back(str.at(i));
		}
	}
	return result;
}