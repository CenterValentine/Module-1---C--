#include "analyzer.hpp"
#include <cctype>
#include <iostream>

namespace core {


// Character and character type specific stats.
void CharacterStats::analyzerCount(std::string_view line) noexcept {
characters += line.size();

for (unsigned char c : line){
if (std::isalpha(c)) ++letters;
else if (std::isdigit(c)) ++integers;
else if (std::isspace(c)) ++spaces;
else if ( c == ',') ++commas;
else if ( c == '.') ++periods;
else if ( c == '!') ++exclamations;
else if ( c == '?') ++question_marks;
else ++other_characters;
}
 
}

//Line statistics of the file. Counts every line, empty and line size.
void LineStats::analyzerCount(std::string_view line) noexcept {
++lines;
if (line.empty()) ++empty_lines;
if (line.size() > max_line_length) max_line_length = line.size();
}

//simple function check if a character is alphanumeric.
static inline bool is_alpha(unsigned char c) noexcept {
return std::isalnum(c) || c == '\'' || c == '_';
}

// Called by next_token.  Adds words to a 
void WordStats::addToken(std::string_view token){
if (token.empty()) return;
++words;
std::string key;
// reserves memory for the word/token to be added to a vector.
key.reserve(token.size());
for (unsigned char c : token) { key.push_back(static_cast<char>(std::tolower(c))); }
++freq[key];
}



//next_token checks if char* is a word.
std::string_view Analyzer::next_token(std::string_view line, std::size_t& idx) noexcept {

const std::size_t n = line.size();

while (idx < n && !is_alpha(static_cast<unsigned char>(line[idx])))
{++ idx;} //skips non-words
std::size_t word_start = idx;
while (idx < n && is_alpha(static_cast<unsigned char>(line[idx]))) ++idx; //process token
return line.substr(word_start, idx-word_start); // returns word as token
}


// Execute specific analyzing actions: character, line and word actions
void Analyzer::analyze_line(std::string_view line, Report& r) noexcept {
r.chars.analyzerCount(line);
r.lines.analyzerCount(line);
std::size_t i = 0;
//tokenization for words.  
while (i < line.size()){
auto tok = next_token(line, i);
if (!tok.empty()) r.words.addToken(tok);
}
}

// Run analyzing actions from file stream. 
// NOTE: each stream can only be run once!
Report Analyzer::run(std::istream& in, char delimiter){
Report r;
std::string line;
//iterates through each file line
while (std::getline(in, line, delimiter)) { 
//executes actual anayzing actions.
analyze_line(line, r);
}
// returns the report parts object
return r;
}


}