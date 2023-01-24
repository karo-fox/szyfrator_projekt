#pragma once

#include <map>
#include <string>
#include <vector>
#include <set>

#include "UserInterface.h"

#include "CipherStrategy.h"
#include "four_square.h"
#include "CipherCommunicator.h"

class FourSquareCipher : public CipherStrategy {
private:
	std::string keyword1_;
	std::string keyword2_;

	std::vector<Redundant> removed_;
	std::map<SquareCode, SquareMatrix> squares_;
	std::set<std::string> to_remove_{ " ", "q" };

	bool settings_;

	std::string remove_redundant_(const std::string& str);
	std::string insert_redundant_(const std::string& str);
public:
	FourSquareCipher();
	void new_settings(const CipherCommunicator& communicator) override;
	void reset_settings() override;
	std::string encrypt(const std::string& txt) override;
	std::string decrypt(const std::string& txt) override;
};