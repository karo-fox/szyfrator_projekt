#pragma once

#include <string>
#include <vector>
#include <utility>

/// <summary>
/// Codes of each square used in Four Sqaure Cipher
/// </summary>
enum class SquareCode {
	top_left, top_right, bottom_left, bottom_right
};

/// <summary>
/// Saves redundant characters removed from plaintext with their positions
/// </summary>
struct Redundant {
	const std::string letter;
	int position;
};


/// <summary>
/// Creates a 5x5 matrix containing letters of alphabet.
/// It begins with provided keyword (without duplicate letters)
/// and begins with consecutive letters of alphabet without "q"
/// (dropping characters that are already in the keyword)
/// </summary>
class SquareMatrix {
private:
	/// <summary>
	/// 5x5 matrix of letters
	/// </summary>
	std::vector<std::string> matrix_;
public:
	SquareMatrix(const std::string& keyword = "");

	/// <summary>
	/// Finds a character inside the matrix
	/// </summary>
	/// <param name="row">The number of row</param>
	/// <param name="col">The number of column</param>
	/// <returns>The character</returns>
	const char at(int row, int col) const;
	
	/// <summary>
	/// Finds the coordinates of letter inside the matrix
	/// </summary>
	/// <param name="letter">The letter to find coordinates of</param>
	/// <returns>A pair of row and column</returns>
	std::pair<int, int> find(char letter) const;
};
