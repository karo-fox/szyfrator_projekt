#pragma once

enum Language {
	en, pl,
};

struct Settings {
	Language lang{ Language::en };
	bool save_to_file_{ false };
};