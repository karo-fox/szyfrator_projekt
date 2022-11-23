#pragma once

#include "UserInterface.h"

class CipherSetter {
protected:
	const UserInterface& ui_;
public:
	CipherSetter(const UserInterface& ui) : ui_{ ui } {};
};