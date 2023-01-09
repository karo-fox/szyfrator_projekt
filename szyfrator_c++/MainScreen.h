#pragma once

#include <map>
#include <string>

#include "screens.h"
#include "UserInterface.h"
#include "MainScreenCommunicator.h"

#include "EncryptionContext.h"

/// <summary>
/// Main Screen for the program
/// </summary>
class MainScreen : public Screen {
private:
	const std::map<std::string, ScreenType> change_screen_{
		{"settings", ScreenType::settings},
		{"start", ScreenType::stay},
	};

	const MainScreenCommunicator communicator_;
	EncryptionContext& context_;
public:
	MainScreen(UserInterface& ui, EncryptionContext& context)
		: Screen{ ui }, communicator_{ ui }, context_{ context } {};
	/// <summary>
	/// Presents some actions for user to take:
	/// - go to settings
	/// - start encrypting/decrypting
	/// - quit
	/// </summary>
	/// <returns>Screen that should be run next</returns>
	ScreenType run() const override;

	void start_encryption() const;

	void provide_cipher(Cipher cipher_code) const;
};
