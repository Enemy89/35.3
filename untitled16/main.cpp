#include <iostream>
#include <filesystem>
#include <vector>
#include <string>

int main() {
    auto findFilesByExtension = [](const std::string& directory, const std::string& extension) {
        std::vector<std::string> result;

        for (const auto& entry : std::filesystem::directory_iterator(directory)) {
            if (entry.is_regular_file() && entry.path().extension() == extension) {
                result.push_back(entry.path().filename().string());
            }
        }
        return result;
    };

    std::string directoryPath = "C:\\untitled16";
    std::string targetExtension = ".txt";

    std::vector<std::string> files = findFilesByExtension(directoryPath, targetExtension);

    std::cout << "Files '" << targetExtension << "' in '" << directoryPath << "':\n";
    for (const auto& file : files) {
        std::cout << file << "\n";
    }
}
