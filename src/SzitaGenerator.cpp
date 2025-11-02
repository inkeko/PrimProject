#include "SzitaGenerator.hpp"
#include <cmath>

std::vector<bool> SzitaGenerator::szita;
int SzitaGenerator::maxSzam = 0;

void SzitaGenerator::general(int max) {
    if (max <= maxSzam) return;

    int size = (max / 2) + 1; // csak páratlan számokat tárolunk
    szita = std::vector<bool>(size, true);
    szita[0] = false; // 1 nem prím

    int limit = static_cast<int>(std::sqrt(max));
    for (int i = 3; i <= limit; i += 2) {
        if (szita[i / 2]) {
            for (int j = i * i; j <= max; j += 2 * i) {
                szita[j / 2] = false;
            }
        }
    }

    maxSzam = max;
}

bool SzitaGenerator::ellenoriz(int szam) {
    if (szam == 2) return true;
    if (szam < 2 || szam % 2 == 0) return false;
    return szita[szam / 2];
}

bool SzitaGenerator::isGenerated(int szam) {
    return szam <= maxSzam;
}