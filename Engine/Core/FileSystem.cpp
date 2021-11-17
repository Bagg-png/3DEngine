#include "FileSystem.h"
#include <filesystem>

namespace ag {

	void ag::SetFilePath(const std::string& pathname)
	{
		std::filesystem::current_path(pathname);
	}
	std::string ag::GetFilePath()
	{
		return std::filesystem::current_path().string();
	}
}