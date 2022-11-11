#pragma once

#include <string>

class CipherStrategy {
public:
	virtual ~CipherStrategy() = default;
	virtual std::string encrypt(std::string& txt) const = 0;
	virtual std::string decrypt(std::string& txt) const = 0;
};