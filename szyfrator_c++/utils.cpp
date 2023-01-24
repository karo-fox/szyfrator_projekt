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

std::vector<std::string> split_in_pairs(const std::string& str) {
	std::vector<std::string> result;
	for (int i{}; i < str.size(); i+=2) {
		result.push_back(str.substr(i, 2));
	}
	return result;
};

std::string str_to_lower(const std::string& str) {
	std::string result;
	for (auto& letter : str) {
		result.push_back(std::tolower(letter));
	}
	return result;
}