#pragma once

#include <string>
#include <vector>

#include "Communicator.h"
#include "UserInterface.h"
#include "lang.h"

/// <summary>
/// Communicator for Screens
/// </summary>
class ScreenCommunicator : public Communicator {
protected:
	/// <summary>
	/// Code of the prompt for actions to present
	/// </summary>
	const LangCode actions_prompt_code_;

	/// <summary>
	/// The vector of available actions
	/// </summary>
	const std::vector<std::string> available_actions_;
public:
	ScreenCommunicator(
		UserInterface& ui, 
		const LangCode actions_prompt_code, 
		const std::vector<std::string>& available_actions
	) : Communicator{ ui }, 
		actions_prompt_code_{ actions_prompt_code }, 
		available_actions_{ available_actions } 
	{};

	/// <summary>
	/// Shows Screen's title in a frame
	/// </summary>
	/// <param name="title">Screen's title to show</param>
	void show_title(const std::string& title) const;

	/// <summary>
	/// Present available actions to user
	/// </summary>
	void show_actions() const;


	/// <summary>
	/// Asks user which action to take
	/// </summary>
	/// <returns></returns>
	std::string get_action() const;

	/// <summary>
	/// Show approprate prompt in case an action is not found
	/// (This should not happen)
	/// </summary>
	void action_not_found() const;
};
