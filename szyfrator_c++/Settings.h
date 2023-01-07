#pragma once

enum Language {
	en, pl,
};

/// <summary>
/// Stores user settings:
/// - UI langauge
/// - save to file option
/// </summary>
struct Settings {
	Language lang{ Language::en };
	bool save_to_file_{ false };
};