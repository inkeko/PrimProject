#include "simd_utils.hpp"
#include <xsimd/xsimd.hpp>
#include <algorithm>

namespace simd_utils {

void simd_fill_auto(std::vector<char>& vec, char value) {
    using batch_type = xsimd::batch<char>;
    std::size_t simd_size = batch_type::size;
    std::size_t vec_size = vec.size();

    batch_type fill_value(value);
    std::size_t i = 0;

    for (; i + simd_size <= vec_size; i += simd_size) {
        fill_value.store_unaligned(&vec[i]);
    }

    // Maradék elemek
    for (; i < vec_size; ++i) {
        vec[i] = value;
    }
}

void simd_clear_multiples(std::vector<char>& vec, int p, int felso) {
    int start = p * p;
    if (start > felso) return;

    // Csak páratlan számokat tárolunk → index: (szam - 1) / 2
    for (int szam = start; szam <= felso; szam += 2 * p) {
        int index = (szam - 1) / 2;
        vec[index] = 0;
    }
}

} // namespace simd_utils