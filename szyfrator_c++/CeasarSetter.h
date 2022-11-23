#pragma once

#include "CipherSetter.h"
#include "ceasar.h"
#include "UserInterface.h"

class CeasarSetter : public CipherSetter {
public:
	CeasarSetter(const UserInterface& ui) : CipherSetter{ ui } {};
	int set_offset() const;
	Direction set_direction() const;
};