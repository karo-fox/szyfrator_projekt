#pragma once

#include "UserInterface.h"
#include "ceasar.h"

class CeasarSetter {
private:
	UserInterface& ui_;
public:
	CeasarSetter(UserInterface& ui);
	int set_offset() const;
	Direction set_direction() const;
};