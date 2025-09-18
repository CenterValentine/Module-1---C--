#include <iostream>
#include <filesystem>
#include <cctype>
#include "core/analyzer.hpp"
#include "adapters/filesystem.hpp"
#include <cstring>


int main(){

// File input path
    std::filesystem::path inputDirectory = "inputs";

//     if (std::filesystem::exists(input)) {
//     // std::cout << "File exists\n";
// } else {
//     // std::cout << "File does not exist\n";
// }

std::filesystem::path filePath;
std::cout << "Welcome to file analyzer I \n";
std::cout << "Please enter the file you wish to process:\n";
for (const auto & entry : std::filesystem::directory_iterator(inputDirectory)){
    std::cout << entry.path() << "\n" << std::endl;
}
std::cin >> filePath;

auto file = adapters::fs::open_file(inputDirectory / filePath);
    
std::cout << "File contents: \n";
    std::string line;
//     while (std::getline(*file, line)){
// std::cout << line << "\n";
//     }

core::Analyzer analyzer;

auto report = analyzer.run(*file);







    

}