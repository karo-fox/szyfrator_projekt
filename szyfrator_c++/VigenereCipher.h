#pragma once

#include <string>

#include "CipherStrategy.h"
#include "CipherCommunicator.h"
#include "ceasar.h"

#include "UserInterface.h"

class VigenereCipher : public CipherStrategy {
private:
	std::string keyword_;
	Direction direction_;
	bool settings_;
public:
	VigenereCipher();
	void new_settings(const CipherCommunicator& communicator) override;
	void reset_settings() override;
	std::string encrypt(const std::string& txt) override;
	std::string decrypt(const std::string& txt) override;
};