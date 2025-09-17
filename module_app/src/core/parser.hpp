#pragma once
#include <string>
#include <vector>
#include <cstdint>
#include <cstddef>
#include <stdexcept>
#pragma once
#include <string>

namespace core {
    struct LineStats {
    };
    LineStats analyze_line(const std::string& line);
}