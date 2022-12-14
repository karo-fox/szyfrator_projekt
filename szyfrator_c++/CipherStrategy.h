#pragma once

#include <string>

class CipherStrategy {
public:
	virtual ~CipherStrategy() = default;
	virtual std::string encrypt(const std::string& txt) = 0;
	virtual std::string decrypt(const std::string& txt) = 0;
	virtual void new_settings() = 0;
	virtual void reset_settings() = 0;
};