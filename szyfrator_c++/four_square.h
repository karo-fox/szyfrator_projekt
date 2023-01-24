#pragma once

#include <string>
#include <vector>
#include <utility>

enum class SquareCode {
	top_left, top_right, bottom_left, bottom_right
};

struct Redundant {
	const std::string letter;
	int position;
};

class SquareMatrix {
private:
	std::vector<std::string> matrix_;

	std::string unique_combine(
		const std::string& add_str, const std::string& unique_str = "") const;
public:
	SquareMatrix(const std::string& keyword = "");
	const char at(int x, int y) const;
	std::pair<int, int> find(char letter) const;
};