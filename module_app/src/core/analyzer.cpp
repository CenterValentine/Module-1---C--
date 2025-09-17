#include "core/analyzer.hpp"
#include cctype

namespace core {

void CharacterStats::analyzerCount(std::string_view line) noexcept {
char_count += line.size();
for (unsigned char c : line){
if (std:isalpha(c)) ++letters;
else if (std:isdigit(c)) ++digits;
else if (std::isspace(c)) ++whitespace;
else if ( c == ',') ++comma_count;
else if ( c == '.') ++period_count;
else if ( c == '!') ++exclamation_count;
else if ( c == '?') ++question_m_count;
else ++other_char_count;
}
 
}

void LineStats::analyzerCount(std:string_view line) noexcept {
++line_count;
if (line.empty()) ++empty_line_count;
if (line.size() > max_line_len) max_line_length = line.size();
};

void WordStats::addToken(std:string_view token){

};




}