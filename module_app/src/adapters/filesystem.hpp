#pragma once
#include <istream>
#include <memory>
#include <string>
#include <filesystem>

namespace adapters::fs {
    std::unique_ptr<std::istream> open_file(const std::filesystem::path& path);

    void write_file(const std::filesystem::path& path, const std::string& contents);
}