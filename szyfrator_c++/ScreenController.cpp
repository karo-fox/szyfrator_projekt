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
	screens_.insert(
		std::make_pair(ScreenType::main_menu, std::make_shared<MenuScreen>(main_menu))
	);
	auto settings = SettingsScreen{ ui };
	screens_.insert(
		std::make_pair(ScreenType::settings, std::make_shared<SettingsScreen>(settings))
	);
	auto encryption = EncryptionScreen{ ui };
	screens_.insert(
		std::make_pair(ScreenType::encryption, std::make_shared<EncryptionScreen>(encryption))
	);
	screen_stack_.push(std::make_shared<MenuScreen>(main_menu));
}

void ScreenController::start() {
	while (true) {
		auto next = screen_stack_.top().get()->run();
		if (next == ScreenType::back) {
			screen_stack_.pop();
		}
		else if (next != ScreenType::stay) {
			screen_stack_.push(screens_.at(next));
		}
	}
}