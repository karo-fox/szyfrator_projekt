#pragma once

#include <string>
#include "CipherStrategy.h"

enum Direction {
	right,
	left
};

class CeasarCipher : public CipherStrategy {
	int offset_;
	Direction direction_;
public:
	CeasarCipher(int offset, Direction direction = Direction::right);
	std::string encrypt(std::string& txt) const;
	std::string decrypt(std::string& txt) const;
};