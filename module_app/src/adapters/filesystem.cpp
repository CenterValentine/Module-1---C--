#include "filesystem.hpp"
#include <fstream>
#include <string>
#include <stdexcept>
#include <memory>
#include <filesystem>


namespace adapters::fs {


    std::unique_ptr<std::istream> open_file(const std::filesystem::path& path){
        auto file = std::make_unique<std::ifstream>(path);
        // exceptions precaution for input/output errors
        file->exceptions(std::ios::badbit | std::ios::failbit);

        // exception for failure to open
        if (!file->is_open()){
            throw std::runtime_error(std::string("Cannot open file: ") + path.string());
        }
        return file;
    }

    // unique_ptr manages file memory.  For learning purposes, a mirroring function with the manual memory should be attempted
    // make_unique sets up a unique input file stream (ifstream)


    void write_file(const std::filesystem::path& path, const std::string& contents){

    //  output(filename, open or overwrite) - "outputs a file stream called output, open the file at path for writing, overwrite if needed.”
    std::ofstream output(path, std::ios::out | std::ios::trunc);

    output.exceptions(std::ios::badbit | std::ios::failbit);
    // writing alternatives: std::ios::app (add to end of file).  std::ios::binary ()

    // exceptions if failed to open
    if (!output.is_open()){
            throw std::runtime_error(std::string("Cannot open file for writing: ") + path.string());
        }

        output << contents;

}


}

