#pragma once

#include <string>
#include "CipherStrategy.h"
#include "CeasarSetter.h"
#include "ceasar.h"


class CeasarCipher : public CipherStrategy {
private:
	int offset_;
	Direction direction_;
	bool settings_; // true if settings are different from reset_settings();
	CeasarSetter& setter_;

public:
	CeasarCipher(CeasarSetter& setter);
	void new_settings() override;
	void reset_settings() override;
	std::string encrypt(std::string& txt) const override;
	std::string decrypt(std::string& txt) const override;
};