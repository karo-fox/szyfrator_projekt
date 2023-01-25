#pragma once

#include <string>
#include <fstream>
#include <chrono>

/// <summary>
/// Manages saving text into a file
/// </summary>
class FileManager {
private:

	/// <summary>
	/// Format string for file name
	/// </summary>
	static constexpr std::string_view format_str_{
		"encryptor_{0:%Y}_{0:%m}_{0:%C}_{0:%H}{0:%M}{0:%OS}.txt"
	};

	/// <summary>
	/// Directory for saving files
	/// </summary>
	const std::string directory_{"..\\encryptionFiles\\"};

	/// <summary>
	/// Gets current time
	/// </summary>
	/// <returns>Current time</returns>
	std::chrono::time_point<std::chrono::utc_clock> get_time_point_() const;

	/// <summary>
	/// Generates file name from the current time
	/// </summary>
	/// <returns>File name</returns>
	std::string generate_file_name_() const;

	/// <summary>
	/// Creates new output file
	/// </summary>
	/// <returns>Output file</returns>
	std::ofstream create_new_write_file_() const;
public:
	FileManager();

	/// <summary>
	/// Saves a content into a new file
	/// </summary>
	/// <param name="content">Text to save into a file</param>
	void save_to_file_(std::string content) const;
};
