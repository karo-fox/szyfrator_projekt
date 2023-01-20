#pragma once

#include <string>
#include <fstream>
#include <chrono>

class FileManager {
private:
	static constexpr std::string_view format_str_{
		"encryptor_{0:%Y}_{0:%m}_{0:%C}_{0:%H}{0:%M}{0:%OS}.txt"
	};

	const std::string directory_{"..\\encryptionFiles\\"};
	std::chrono::time_point<std::chrono::utc_clock> get_time_point_() const;
	std::string generate_file_name_() const;
	std::ofstream create_new_write_file_() const;
public:
	FileManager();
	void save_to_file_(std::string content) const;
};