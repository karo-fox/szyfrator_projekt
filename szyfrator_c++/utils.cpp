#include <vector>
#include <string>
#include <set>

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

bool vec_is_empty(std::vector<std::string> vec) {
	for (std::string& str : vec) {
		if (str != "") {
			return false;
		}
	}
	return true;
}

std::string unique_combine(
	const std::string& add_str, const std::string& unique_str
) {
	std::string result{ unique_str };
	for (auto& elem : add_str) {
		if (result.find(elem) == std::string::npos) {
			result.push_back(elem);
		}
	}
	return result;
}

std::string trim(const std::string& str) {
	std::string result{ rtrim(ltrim(str)) };
	return result;
}

std::string ltrim(const std::string& str) {
	std::string result;
	int pos{};
	while (pos < str.size() && std::isspace(str.at(pos))) {
		pos++;
	}
	if (pos == str.size()) {
		return ""; 
	}
	else {
		return str.substr(pos);
	}
}

std::string rtrim(const std::string& str) {
	std::string result;
	int pos{ static_cast<int>(str.size() - 1) };
	while (pos >= 0 && std::isspace(str.at(pos))) {
		pos--;
	}
	if (pos == 0) {
		return "";
	}
	else {
		return str.substr(0, pos + 1);
	}
}