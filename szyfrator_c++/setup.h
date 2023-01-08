#pragma once

#include <map>

#include "UserInterface.h"
#include "ciphers.h"
#include "CipherStrategy.h"

/// <summary>
/// Initializes all ciphers and stores them in a map
/// </summary>
/// <param name="ui">User Interface for respective Cipher Communicators</param>
/// <returns>Map storing all ciphers</returns>
std::map<Cipher, CipherStrategy&> setup_ciphers(UserInterface& ui);