
#include "core/parser.hpp"
#include "adapters/filesystem.hpp"
#include <iostream>


int main(){


// File input path
    std::string input = "/Users/davidvalentine/Documents/Learning/CSE310 Applied Programming/Module 1 - C++/module_app/inputs/input.txt";

    if (std::filesystem::exists(input)) {
    std::cout << "File exists ✅\n";
} else {
    std::cout << "File does not exist ❌\n";
}

    // adapters::fs::open_file(input);

}