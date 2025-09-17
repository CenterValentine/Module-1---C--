#pragma once
#include <istream>
#include <string>
#include <vector>
#include <string_view>
#include <unordered_map>

namespace core {


struct CharacterStats{
std::size_t char_count = 0;
std::size_t letters = 0;
std::size_t integers = 0;
std::size_t spaces = 0;
std::size_t comma_count = 0;
std::size_t period_count = 0;
std::size_t exclamation_count = 0;
std::size_t question_m_count = 0;
std::size_t other_char_count = 0;
void analyzerCount(std::string_view line) noexcept;
};


struct LineStats {
std::size_t line_count = 0;
std::size_t empty_line_count = 0;
std::size_t max_line_length = 0;
std::vector<int> line_word_counts;
void analyzerCount(std::string_view line) noexcept;
};

struct WordCount {
std::string word;
std:size_t count = 0};

struct WordStats {
std:size_t word_count = 0;
std::vector<WordCount> frequency; // collection of {word, count}
void addToken(std:string_view token);
};

struct Report {
CharacterStats chars;
LineStats lines;
WordStats words;
};

class Analyzer {
public:
Report run(std:istream& in);


private:
void analyze_line(std:string_view line, Report& r) noexcept;

static std::string_view next_token(std::string_view s, std:size_t& i) noexcept;

};