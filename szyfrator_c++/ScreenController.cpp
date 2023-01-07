#include <map>
#include <utility>
#include <stack>
#include <functional>
#include <memory>

#include "ScreenController.h"
#include "screens.h"
#include "MenuScreen.h"
#include "SettingsScreen.h"
#include "EncryptionScreen.h"
#include "UserInterface.h"


ScreenController::ScreenController(UserInterface& ui) {
	auto main_menu = MenuScreen{ ui };
	ScreenController::screens_.insert(
		std::make_pair(ScreenType::main_menu, std::make_shared<MenuScreen>(main_menu))
	);
	auto settings = SettingsScreen{ ui };
	ScreenController::screens_.insert(
		std::make_pair(ScreenType::settings, std::make_shared<SettingsScreen>(settings))
	);
	auto encryption = EncryptionScreen{ ui };
	ScreenController::screens_.insert(
		std::make_pair(ScreenType::encryption, std::make_shared<EncryptionScreen>(encryption))
	);
	ScreenController::screen_stack_.push(std::make_shared<MenuScreen>(main_menu));
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