#pragma once

#include <map>
#include <string>

#include "screens.h"
#include "UserInterface.h"
#include "EncryptionScreenCommunicator.h"

#include "EncryptionContext.h"
#include "ciphers.h"

/// <summary>
/// Manages actions connected with encrypting and decrypting messages
/// </summary>
class EncryptionScreen : public Screen {
private:
	const std::map<std::string, ScreenType> change_screen_{
		{"back", ScreenType::back}
	};

	const EncryptionScreenCommunicator communicator_;
	EncryptionContext& context_;
public:
	EncryptionScreen(UserInterface& ui, EncryptionContext& context)
		: Screen{ ui }, communicator_{ ui }, context_{ context } {};
	/// <summary>
	/// Presents some actions for user to take:
	/// - encrypt or decrypt a message
	/// - go back
	/// </summary>
	/// <returns></returns>
	ScreenType run() const override;

	void start_encryption() const;

	void provide_cipher(Cipher cipher_code) const;
};