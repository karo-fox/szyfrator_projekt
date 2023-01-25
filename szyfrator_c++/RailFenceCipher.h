#pragma once

#include <string>
#include <set>

#include "CipherStrategy.h"
#include "CipherCommunicator.h"

class RailFenceCipher : public CipherStrategy {
private:
	int rails_;
	bool settings_;

	std::set<std::string> redundant_{ " ", ".", ",", "!", "?" };
	std::string remove_redundant_(const std::string& str);
public:
	RailFenceCipher();
	void new_settings(const CipherCommunicator& communicator) override;
	void reset_settings() override;
	std::string encrypt(const std::string& txt) override;
	std::string decrypt(const std::string& txt) override;
};