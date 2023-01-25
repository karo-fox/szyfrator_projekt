#pragma once

#include <map>
#include <string>

#include "screens.h"
#include "UserInterface.h"
#include "MainScreenCommunicator.h"

#include "EncryptionContext.h"
#include "FileManager.h"

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
	const FileManager& file_manager_;

	void provide_cipher_(Cipher cipher_code) const;
public:
	MainScreen(
		UserInterface& ui, 
		EncryptionContext& context, 
		const FileManager& file_manager
	) : 
		Screen{ ui }, 
		communicator_{ ui }, 
		context_{ context }, 
		file_manager_{ file_manager } 
	{};
	/// <summary>
	/// Presents some actions for user to take:
	/// - go to settings
	/// - start encrypting/decrypting
	/// - quit
	/// </summary>
	/// <returns>Screen that should be run next</returns>
	ScreenType run() const override;

	std::string start_encryption() const;
};
