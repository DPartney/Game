#pragma once
#include <filesystem>
#include <string>

namespace shadow {
	std::string GetFilePath();
	bool SetFilePath(const std::filesystem::path& path);
	bool FileExists(const std::filesystem::path& path);
	bool GetFileSize(const std::filesystem::path& path, size_t& size);
	bool ReadFile(const std::filesystem::path& path, std::string& buffer);
}