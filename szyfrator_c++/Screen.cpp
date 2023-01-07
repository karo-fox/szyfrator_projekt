#include <string>
#include <vector>

#include "screens.h"
#include "utils.h"

void Screen::show_title(const std::string& title) const {
	std::string prompt{};
	std::string line(80, '*');
	std::string space(78, ' ');
	// int before = (78 - title.size()) / 2;
	// int after = (78 - title.size() - before);
	prompt += '\n' + line + '\n';
	prompt += '*' + space + '*' + '\n';

	std::vector<std::string> lines = split_str(title, '\n');
	for (auto& line : lines) {
		int before = (78 - line.size()) / 2;
		int after = 78 - line.size() - before;
		prompt += '*' + std::string(before, ' ') + line + std::string(after, ' ') + "*\n";
	}

	// prompt += '*' + std::string(before, ' ') + title + std::string(after, ' ') + '*' + '\n';
	
	
	prompt += '*' + space + '*' + '\n';
	prompt += line + '\n';
	Screen::ui_.show_text(prompt);
}