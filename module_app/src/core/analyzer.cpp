#include "analyzer.hpp"
#include <cctype>
#include <iostream>

namespace core {

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

void LineStats::analyzerCount(std::string_view line) noexcept {
++lines;
if (line.empty()) ++empty_lines;
if (line.size() > max_line_length) max_line_length = line.size();
}

static inline bool is_alpha(unsigned char c) noexcept {
return std::isalnum(c) || c == '\'' || c == '_';
}

void WordStats::addToken(std::string_view token){
if (token.empty()) return;
++words;
std::string key;
key.reserve(token.size());
for (unsigned char c : token) {key.push_back(std::tolower(c));}
++freq[key];
}

std::string_view Analyzer::next_token(std::string_view line, std::size_t& idx) noexcept {

const std::size_t n = line.size();

while (idx < n && !is_alpha(static_cast<unsigned char>(line[idx])))
{++ idx;} //skips non-words
std::size_t word_start = idx;
while (idx < n && is_alpha(static_cast<unsigned char>(line[idx]))) ++idx; //process token
return line.substr(word_start, idx-word_start);
}

void Analyzer::analyze_line(std::string_view line, Report& r) noexcept {

r.chars.analyzerCount(line);

r.lines.analyzerCount(line);
std::size_t i = 0;
while (i < line.size()){
auto tok = next_token(line, i);
if (!tok.empty()) r.words.addToken(tok);
}
}


Report Analyzer::run(std::istream& in, char delimiter){
Report r;
std::string line;
while (std::getline(in, line, delimiter)) { 
analyze_line(line, r);
}
return r;
}


}