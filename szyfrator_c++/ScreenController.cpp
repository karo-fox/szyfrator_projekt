#include <map>
#include <utility>
#include <stack>
#include <functional>
#include <memory>

#include "ScreenController.h"
#include "screens.h"
#include "MainScreen.h"
#include "SettingsScreen.h"
#include "UserInterface.h"
#include "EncryptionContext.h"


ScreenController::ScreenController(UserInterface& ui, EncryptionContext& context) {
	auto main = MainScreen{ ui, context };
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
			ScreenController::screen_stack_.push(ScreenController::screens_[next]);
		}
	}
}