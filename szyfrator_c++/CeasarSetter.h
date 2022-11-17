#pragma once

#include "UserInterface.h"
#include "ceasar.h"

class CeasarSetter {
private:
	const UserInterface& ui_;
public:
	CeasarSetter(const UserInterface& ui);
	int set_offset() const;
	Direction set_direction() const;
};