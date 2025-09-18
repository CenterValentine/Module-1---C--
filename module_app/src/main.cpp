#include <iostream>
#include <filesystem>
#include "core/analyzer.hpp"
#include "core/report.hpp"
#include "adapters/filesystem.hpp"


int main(){

// File input path
    std::filesystem::path inputDirectory = "inputs";
    std::filesystem::path outputDirectory = "outputs";

//     if (std::filesystem::exists(input)) {
//     // std::cout << "File exists\n";
// } else {
//     // std::cout << "File does not exist\n";
// }

std::filesystem::path filePath;
std::cout << "Welcome to file analyzer \n";
std::cout << "Please enter the file you wish to process:\n";

// show available input files.
for (const auto & entry : std::filesystem::directory_iterator(inputDirectory)){
    std::cout << entry.path() << "\n" << std::endl;
}
std::cin >> filePath;

//open the file
auto file = adapters::fs::open_file(inputDirectory / filePath);
    
std::cout << "File contents: \n";
    std::string line;
//     while (std::getline(*file, line)){
// std::cout << line << "\n";
//     }

core::Analyzer analyzer;

auto report = analyzer.run(*file);
std::string saveFile;


// save file option
while (true) {
    std::cout << "Would you like to save this report as json or text? (json/text) ";
    std::cin >> saveFile;
    if (saveFile == "json" || saveFile == "JSON") {
        std::filesystem::create_directories(outputDirectory);
        // stem modifies the report name.
        auto outPath = outputDirectory / (filePath.stem().string() + "_report.json");
        adapters::fs::write_file(outPath, core::to_json(report));
        std::cout << "Saved report to: " << outPath << "\n";
        break;
    } else if (saveFile == "text" || saveFile == "txt") {
          std::filesystem::create_directories(outputDirectory);
        // stem modifies the report name.
        auto outPath = outputDirectory / (filePath.stem().string() + "_report.txt");
        adapters::fs::write_file(outPath, core::to_text(report));
        std::cout << "Saved report to: " << outPath << "\n";
        break;
    } else {
        std::cout << "Invalid input. Please enter 'json' or 'text'.\n";
    }
}
    

}