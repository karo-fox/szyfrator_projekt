#include <chrono>
#include <fstream>
#include <string>
#include <fmt/core.h>
#include <filesystem>

#include "FileManager.h"
#include "FileException.h"

std::chrono::time_point<std::chrono::system_clock> FileManager::get_time_point_() const {
	return std::chrono::system_clock::now();
}

std::string FileManager::generate_file_name_() const {
	return fmt::format(FileManager::format_str_, FileManager::get_time_point_());
}

std::ofstream FileManager::create_new_write_file_() const {
	std::string path{ directory_ + generate_file_name_() };
	std::ofstream file{ path };
	if (!file) {
		throw FileException("Could not create a file", file);
	}
	return file;
}

FileManager::FileManager() {
	std::filesystem::create_directory(FileManager::directory_);
}

void FileManager::save_to_file_(std::string content) const {
	std::ofstream file{ create_new_write_file_() };
	file << content;
}
