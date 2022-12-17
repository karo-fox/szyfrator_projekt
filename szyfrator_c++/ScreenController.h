#pragma once

#include <map>
#include <utility>
#include <stack>
#include <functional>
#include <memory>

#include "screens.h"
#include "UserInterface.h"


class ScreenController {
private:
	std::map<ScreenType, std::shared_ptr<Screen>> screens_{};
	std::stack<std::shared_ptr<Screen>> screen_stack_;
public:
	ScreenController(const UserInterface& ui);
	void start();
};