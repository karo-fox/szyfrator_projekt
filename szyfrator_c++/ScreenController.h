#pragma once

#include <map>
#include <utility>
#include <stack>
#include <memory>

#include "screens.h"
#include "UserInterface.h"

#include "EncryptionContext.h"
#include "FileManager.h"

/// <summary>
/// Controls which Screen is presented to the user
/// </summary>
class ScreenController {
private:
	/// <summary>
	/// Stores all available Screens
	/// </summary>
	std::map<ScreenType, std::shared_ptr<Screen>> screens_{};

	/// <summary>
	/// Keeps track of active and previous Screens
	/// </summary>
	std::stack<std::shared_ptr<Screen>> screen_stack_;
public:
	/// <summary>
	/// Puts all available screen into screens_ 
	/// and pushes Main Screen on top of the screen_stack_
	/// </summary>
	/// <param name="ui">User Interface for Screen initialization</param>
	ScreenController(
		UserInterface& ui, EncryptionContext& context, const FileManager& file_manager
	);

	/// <summary>
	/// Runs Screens in a loop
	/// </summary>
	void start();
};
