#include "SIMDSzita.hpp"
#include "simd_utils.hpp"
#include <thread>
#include <vector>
#include <iostream>
#include <cmath>

SIMDSzita::SIMDSzita(int also, int felso)
    : alsoHatar(also), felsoHatar(felso) {
    int meret = (felsoHatar - 1) / 2 + 1;
    szita.resize(meret);
}

void SIMDSzita::futtat() {
    simd_utils::simd_fill_auto(szita, 1);

    int maxIndex = (int)std::sqrt(felsoHatar) / 2;
    std::vector<std::thread> szalak;

    for (int i = 1; i <= maxIndex; ++i) {
        if (szita[i]) {
            int p = 2 * i + 1;
            szalak.emplace_back([=, this]() {
                simd_utils::simd_clear_multiples(szita, p, felsoHatar);
            });
        }
    }

    for (auto& szal : szalak) {
        szal.join();
    }
}

void SIMDSzita::kiir() const {
    if (felsoHatar == 2) {
        std::cout << "2 ";
        return;
    }

    if (felsoHatar % 2 == 0 || felsoHatar < 2) return;

    int index = (felsoHatar - 1) / 2;
    if (szita[index]) {
        std::cout << felsoHatar << " ";
    }
}

bool SIMDSzita::isPrim(int szam) const {
    if (szam == 2) return true;
    if (szam < 2 || szam % 2 == 0) return false;
    int index = (szam - 1) / 2;
    if (index < 0 || index >= szita.size()) return false;
    return szita[index];
}