#pragma once

/// <summary>
/// Available ciphers
/// </summary>
enum class Cipher {
	ceasar,
	four_square,
	vigenere,
	rail_fence
};

/// <summary>
/// Actions that user can take during encryption
/// </summary>
enum class CipherAction {
	encrypt,
	decrypt,
};