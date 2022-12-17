#pragma once

#include <string>
#include "CipherCommunicator.h"

class CipherStrategy {
public:
	virtual std::string encrypt(const std::string& txt) = 0;
	virtual std::string decrypt(const std::string& txt) = 0;
	virtual void new_settings() = 0;
	virtual void reset_settings() = 0;
	virtual ~CipherStrategy() = default;
};