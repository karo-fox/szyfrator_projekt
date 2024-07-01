#include <vector>
#include <string>

#include "UserInterface.h"
#include "ScreenCommunicator.h"
#include "utils.h"
#include "validators.h"
#include "ValidationException.h"
#include "lang.h"

void ScreenCommunicator::show_title(const std::string& title) const {
	std::string prompt{};
	std::string line(80, '*');
	std::string space(78, ' ');
	prompt += '\n' + line + '\n';
	prompt += '*' + space + '*' + '\n';

	std::vector<std::string> lines = split_str(title, '\n');
	for (auto& line : lines) {
		int before = (78 - line.size()) / 2;
		int after = 78 - line.size() - before;
		prompt += '*' + std::string(before, ' ') + line + std::string(after, ' ') + "*\n";
	}

	prompt += '*' + space + '*' + '\n';
	prompt += line + '\n';
	ui_.show_text(prompt);
}

void ScreenCommunicator::show_actions() const {
	ui_.show_text(ui_.parse(LangCode::available_screen_actions));
	ui_.show_text(ui_.parse(actions_prompt_code_));
}

std::string ScreenCommunicator::get_action() const {
	while (true) {
		ui_.show_text(ui_.parse(LangCode::choose_screen_action) + ": ");
		std::string input = ui_.text_input();
		try {
			validate_not_empty(input);
			validate_allowed(input, available_actions_);
			return input;
		}
		catch (const ValidationException<std::string>& e) {
			ui_.show_text(ui_.parse(e.msg_code_, e.validation_args_));
		}
	}
}

void ScreenCommunicator::action_not_found() const {
	 ui_.show_text(ui_.parse(LangCode::action_not_found));
}
