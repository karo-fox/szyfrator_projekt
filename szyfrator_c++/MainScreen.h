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
	/// <summary>
	/// Screen that can come after this one
	/// </summary>
	const std::map<std::string, ScreenType> change_screen_{
		{"settings", ScreenType::settings},
		{"start", ScreenType::stay},
	};

	/// <summary>
	/// Communicator for this screen
	/// </summary>
	const MainScreenCommunicator communicator_;

	/// <summary>
	/// EncryptionContext for managing encryption
	/// </summary>
	EncryptionContext& context_;

	/// <summary>
	/// FileManager for managing saving an encryption result to file
	/// </summary>
	const FileManager& file_manager_;

	/// <summary>
	/// Changes the active cipher in EncryptionContext
	/// </summary>
	/// <param name="cipher_code">Code of the cipher to be set as active</param>
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

	/// <summary>
	/// Starts the encrpytion of the message
	/// </summary>
	/// <returns>Encrypted text</returns>
	std::string start_encryption() const;
};
