#pragma once
#include <istream>
#include <string>
#include <vector>
#include <string_view>
#include <unordered_map>

namespace core {

// Stat structure for Characters
struct CharacterStats{
std::size_t characters = 0;
std::size_t letters = 0;
std::size_t integers = 0;
std::size_t spaces = 0;
std::size_t commas = 0;
std::size_t periods = 0;
std::size_t exclamations = 0;
std::size_t question_marks = 0;
std::size_t other_characters = 0;
void analyzerCount(std::string_view line) noexcept;
};

// Stat structure for file lines
struct LineStats {
std::size_t lines = 0;
std::size_t empty_lines = 0;
std::size_t max_line_length = 0;
std::vector<int> line_words;
void analyzerCount(std::string_view line) noexcept;
};

// Stat structure for words
struct WordStats {
std::size_t words = 0;
std::unordered_map<std::string, std::size_t> freq;      // collection of {word, count}
void addToken(std::string_view token);
};

// Stat structure for report parts
struct Report {
CharacterStats chars;
LineStats lines;
WordStats words;
};



class Analyzer {
public:

// filetype is a stream input. A delimiter overide is option.
Report run(std::istream& in, char delimiter  = '\n');


private:
// declares the lines of text-file data to be iterated.
void analyze_line(std::string_view line, Report& r) noexcept;

// file scroll navigation.
static std::string_view next_token(std::string_view s, std::size_t& i) noexcept;
};

}