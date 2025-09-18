#pragma once
#include <ostream>
#include <sstream>
#include <string>
#include "analyzer.hpp"

namespace core {

// Text rendering
inline std::string to_text(const Report& r) {
    std::ostringstream oss;
    oss << "== Line Stats ==\n"
        << "Total lines: " << r.lines.lines << "\n"
        << "Empty lines: " << r.lines.empty_lines << "\n"
        << "Max line length: " << r.lines.max_line_length << "\n\n"

        << "== Word Stats ==\n"
        << "Total words: " << r.words.words << "\n";
    if (!r.words.freq.empty()) {
        oss << "Top words (unsorted dump):\n";
        for (const auto& [w, cnt] : r.words.freq) {
            oss << "  " << w << ": " << cnt << "\n";
        }
    }
    oss << "\n== Character Stats ==\n"
        << "Total characters: " << r.chars.characters << "\n"
        << "Letters: " << r.chars.letters << "\n"
        << "Digits: " << r.chars.integers << "\n"
        << "Spaces: " << r.chars.spaces << "\n"
        << "Commas: " << r.chars.commas << "\n"
        << "Periods: " << r.chars.periods << "\n"
        << "Exclamations: " << r.chars.exclamations << "\n"
        << "Question marks: " << r.chars.question_marks << "\n"
        << "Other characters: " << r.chars.other_characters << "\n";
    return oss.str();
}

// JSON rendering
inline std::string to_json(const Report& r) {
    std::ostringstream oss;
    oss << "{"
        << "\"lines\":{"
            << "\"total\":" << r.lines.lines << ","
            << "\"empty\":" << r.lines.empty_lines << ","
            << "\"max_length\":" << r.lines.max_line_length
        << "},"
        << "\"words\":{"
            << "\"total\":" << r.words.words
        << "},"
        << "\"chars\":{"
            << "\"total\":" << r.chars.characters << ","
            << "\"letters\":" << r.chars.letters << ","
            << "\"digits\":" << r.chars.integers << ","
            << "\"spaces\":" << r.chars.spaces << ","
            << "\"commas\":" << r.chars.commas << ","
            << "\"periods\":" << r.chars.periods << ","
            << "\"exclamations\":" << r.chars.exclamations << ","
            << "\"question_marks\":" << r.chars.question_marks << ","
            << "\"other\":" << r.chars.other_characters
        << "}"
    << "}";
    return oss.str();
}

// Stream uses plain-text
inline std::ostream& operator<<(std::ostream& os, const Report& r) {
    return os << to_text(r);
}

}

