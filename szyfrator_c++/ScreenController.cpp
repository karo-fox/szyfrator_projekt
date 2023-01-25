#include <map>
#include <utility>
#include <stack>
#include <memory>

#include "ScreenController.h"
#include "screens.h"
#include "MainScreen.h"
#include "SettingsScreen.h"
#include "UserInterface.h"
#include "EncryptionContext.h"
#include "FileManager.h"


ScreenController::ScreenController(
	UserInterface& ui, EncryptionContext& context, const FileManager& file_manager
) {
	auto main = MainScreen{ ui, context , file_manager};
	ScreenController::screens_.insert(
		std::make_pair(ScreenType::main_menu, std::make_shared<MainScreen>(main))
	);
	auto settings = SettingsScreen{ ui };
	ScreenController::screens_.insert(
		std::make_pair(ScreenType::settings, std::make_shared<SettingsScreen>(settings))
	);
	ScreenController::screen_stack_.push(std::make_shared<MainScreen>(main));
}

void ScreenController::start() {
	while (true) {
		auto next = ScreenController::screen_stack_.top().get()->run();
		if (next == ScreenType::back) {
			ScreenController::screen_stack_.pop();
		}
		else if (next != ScreenType::stay) {
			ScreenController::screen_stack_.push(ScreenController::screens_.at(next));
		}
	}
}
