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
	const CeasarSetter& setter_;

public:
	CeasarCipher(const CeasarSetter& setter);
	void new_settings() override;
	void reset_settings() override;
	std::string encrypt(const std::string& txt) const override;
	std::string decrypt(const std::string& txt) const override;
};