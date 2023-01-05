#include <string>

#include "screens.h"
#include "UserInterface.h"

void Screen::show_title(const std::string& title) const {
	std::string prompt{};
	std::string line(80, '*');
	std::string space(78, ' ');
	int before = (78 - title.size()) / 2;
	int after = (78 - title.size() - before);
	prompt += '\n' + line + '\n';
	prompt += '*' + space + '*' + '\n';
	prompt += '*' + std::string(before, ' ') + title + std::string(after, ' ') + '*' + '\n';
	prompt += '*' + space + '*' + '\n';
	prompt += line + '\n';
	Screen::ui_.show_text(prompt);
}