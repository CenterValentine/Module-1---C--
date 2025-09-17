#include <iostream>
#include <filesystem>
#include <cctype>
#include "core/analyzer.hpp"
#include "adapters/filesystem.hpp"



int main(){

// File input path
    std::string input = "/Users/davidvalentine/Documents/Learning/CSE310 Applied Programming/Module 1 - C++/module_app/inputs/input.txt";

    if (std::filesystem::exists(input)) {
    // std::cout << "File exists\n";
} else {
    // std::cout << "File does not exist\n";
}

    auto file = adapters::fs::open_file(input);
    
    std::string line;
    while (std::getline(*file, line)){
std::cout << line << "\n";
    }


}