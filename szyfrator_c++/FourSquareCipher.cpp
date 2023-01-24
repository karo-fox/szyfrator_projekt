#include <map>
#include <string>
#include <utility>

#include "FourSquareCipher.h"
#include "four_square.h"
#include "UserInterface.h"
#include "CipherStrategy.h"
#include "FourSquareCommunicator.h"
#include "utils.h"

FourSquareCipher::FourSquareCipher(UserInterface& ui) : communicator_{ ui } {
	FourSquareCipher::reset_settings();
}

void FourSquareCipher::reset_settings() {
	keyword1_ = "";
	keyword2_ = "";
	squares_.clear();
	squares_.insert({ SquareCode::top_left, SquareMatrix{} });
	squares_.insert({ SquareCode::top_right, SquareMatrix{ keyword1_ } });
	squares_.insert({ SquareCode::bottom_left, SquareMatrix{ keyword2_ } });
	squares_.insert({ SquareCode::bottom_right, SquareMatrix{} });
	settings_ = false;
}

void FourSquareCipher::new_settings() {
	keyword1_ = communicator_.set_keyword();
	squares_.at(SquareCode::top_right) = SquareMatrix{ keyword1_ };
	keyword2_ = communicator_.set_keyword();
	squares_.at(SquareCode::bottom_left) = SquareMatrix{ keyword2_ };
	settings_ = true;
}

std::string FourSquareCipher::encrypt(const std::string& txt) {
	std::string result;
	std::vector<std::string> ciphertext{ 
		split_in_pairs(remove_redundant_(str_to_lower(txt))) 
	};
	for (auto& str_pair : ciphertext) {
		auto letter1_xy{ 
			FourSquareCipher::squares_.at(SquareCode::top_left).find(str_pair.at(0))
		};
		auto letter2_xy{
			FourSquareCipher::squares_.at(SquareCode::bottom_right).find(str_pair.at(1))
		};
		result.push_back(
			FourSquareCipher::squares_.at(
				SquareCode::top_right).at(letter1_xy.first, letter2_xy.second
			)
		);
		result.push_back(
			FourSquareCipher::squares_.at(
				SquareCode::bottom_left).at(letter2_xy.first, letter1_xy.second
			)
		);
	}
	result = FourSquareCipher::insert_redundant_(result);
	return result;
}

std::string FourSquareCipher::decrypt(const std::string& txt) {
	std::string result;
	std::vector<std::string> ciphertext{ 
		split_in_pairs(remove_redundant_(str_to_lower(txt))) 
	};
	for (auto& str_pair : ciphertext) {
		auto letter1_xy{
			FourSquareCipher::squares_.at(SquareCode::top_right).find(str_pair.at(0))
		};
		auto letter2_xy{
			FourSquareCipher::squares_.at(SquareCode::bottom_left).find(str_pair.at(1))
		};
		result.push_back(
			FourSquareCipher::squares_.at(
				SquareCode::top_left).at(letter1_xy.first, letter2_xy.second
				)
		);
		result.push_back(
			FourSquareCipher::squares_.at(
				SquareCode::bottom_right).at(letter2_xy.first, letter1_xy.second
				)
		);
	}
	result = FourSquareCipher::insert_redundant_(result);
	return result;
}

std::string FourSquareCipher::remove_redundant_(const std::string& str) {
	FourSquareCipher::removed_.clear();
	std::string result;
	for (int i{}; i < str.size(); i++) {
		if (to_remove_.contains(std::string{ str.at(i) })) {
			FourSquareCipher::removed_.push_back(
				Redundant{ std::string{ str.at(i) }, i }
			);
		}
		else {
			result.push_back(str.at(i));
		}
	}
	if ((str.size() - removed_.size()) % 2 != 0) {
		FourSquareCipher::removed_.push_back(
			Redundant{ 
				std::string{ str.back() }, 
				static_cast<int>(str.size() - 1) 
			}
		);
		result.pop_back();
	}
	return result;
}

std::string FourSquareCipher::insert_redundant_(const std::string& str) {
	std::string result{ str };
	for (auto& elem : FourSquareCipher::removed_) {
		result.insert(elem.position, elem.letter);
	}
	return result;
}