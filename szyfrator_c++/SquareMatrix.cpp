#include <utility>
#include <string>

#include "four_square.h"
#include "Exception.h"
#include "utils.h"

SquareMatrix::SquareMatrix(const std::string& keyword) {
	std::string unique_keyword{ unique_combine(keyword) };
	std::string alphabet{ "abcdefghijklmnoprstuvwxyz" };
	std::string matrix_str{ unique_combine(alphabet, unique_keyword) };
	for (int i{}; i <= 20; i += 5) {
		matrix_.push_back(matrix_str.substr(i, 5));
	}
}

const char SquareMatrix::at(int x, int y) const {
	return matrix_.at(x).at(y);
}

std::pair<int, int> SquareMatrix::find(char letter) const {
	for (int i{}; i < 5; i++) {
		for (int j{}; j < 5; j++) {
			if (this->at(i, j) == letter) {
				return std::pair<int, int>{i, j};
			}
		}
	}
	 throw Exception{ "Letter not found" };
}
