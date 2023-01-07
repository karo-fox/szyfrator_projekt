#include <vector>
#include <string>

#include "utils.h"

std::vector<std::string> split_str(const std::string& str, char sep) {
	std::vector<std::string> words{};
	int idx{};
	std::string word{};
	while (idx <= str.size()) {
		if (str[idx] == sep or str[idx] == '\0') {
			words.push_back(word);
			word = "";
		}
		else {
			word.push_back(str[idx]);
		}
		idx++;
	}
	return words;
};