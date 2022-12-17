#pragma once

#include <map>

#include "UserInterface.h"
#include "ciphers.h"
#include "CipherStrategy.h"

std::map<Cipher, CipherStrategy&> setup_ciphers(const UserInterface& ui);