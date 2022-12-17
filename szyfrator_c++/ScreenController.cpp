#pragma once

#include <map>
#include <utility>
#include <stack>
#include <functional>
#include <memory>

#include "ScreenController.h"
#include "screens.h"
#include "UserInterface.h"


ScreenController::ScreenController(const UserInterface& ui) {
	auto main_menu = MainMenu{ ui };
	ScreenController::screens_.insert(
		std::make_pair(ScreenType::main_menu, std::make_shared<MainMenu>(main_menu))
	);
	ScreenController::screen_stack_.push(std::make_shared<MainMenu>(main_menu));
}

void ScreenController::start() {
	while (true) {
		auto next = ScreenController::screen_stack_.top().get()->run();
		if (next == ScreenType::back) {
			ScreenController::screen_stack_.pop();
		}
		else {
			ScreenController::screen_stack_.push(ScreenController::screens_[next]);
		}
	}
}