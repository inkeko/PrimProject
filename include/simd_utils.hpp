#pragma once
#include <vector>
#include <cstddef>

namespace simd_utils {
    void simd_fill_auto(std::vector<char>& vec, char value);
    void simd_clear_multiples(std::vector<char>& vec, int i, int felso);
}