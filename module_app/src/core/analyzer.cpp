#include "analzyer.hpp"
#include <cctype>

namespace core {

void CharacterStats::analyzerCount(std::string_view line) noexcept {
char_count += line.size();
for (unsigned char c : line){
if (std::isalpha(c)) ++letters;
else if (std::isdigit(c)) ++integers;
else if (std::isspace(c)) ++spaces;
else if ( c == ',') ++comma_count;
else if ( c == '.') ++period_count;
else if ( c == '!') ++exclamation_count;
else if ( c == '?') ++question_m_count;
else ++other_char_count;
}
 
}

void LineStats::analyzerCount(std::string_view line) noexcept {
++line_count;
if (line.empty()) ++empty_line_count;
if (line.size() > max_line_length) max_line_length = line.size();
};

static inline bool is_alpha(unsigned char c) noexcept {
return std::isalnum(c) || c == '\'' || c == '_';
}

void WordStats::addToken(std::string_view token){
if (token.empty()) return;
++word_count;
std::string key;
key.reserve(token.size());
for (unsigned char c : token) {key.push_back(std::tolower(c));}
++freq[key]

};

std::string_view Analyzer::next_token(std::string_view line, std::size_t& idx) noexcept {

const std::size_t n = line.size();

while (idx < n && !is_alpha(static_cast<unsigned char>(line[idx])))
{++ idx } //skips non-words
std::size_t word_start = idx;
while (idx < n && is_alpha(static_cast<unsigned char>(line[idx]))) ++idx; //process token

return line.substr(word_start, idx-word_start);



}

void Analyzer::analyze_line(std::string_view line, Report& r) noexcept; {
r.chars.analyzerCount(line);
r.lines.analyzerCount(line);
while (i < line.size()){
auto tok = next_token(line, i);
if (!tok.empty()) r.words.addToken(tok);
}
}




}