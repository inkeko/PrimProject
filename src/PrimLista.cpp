#include "PrimLista.hpp"
#include <vector>
#include <cmath>

std::unordered_set<int> PrimLista::primSet;
int PrimLista::maxGenerated = 0;

void PrimLista::general(int max) {
    if (max <= maxGenerated) return; // már generálva van

    primSet.clear();
    std::vector<bool> isPrime(max + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= max; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= max; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= max; ++i) {
        if (isPrime[i]) primSet.insert(i);
    }

    maxGenerated = max;
}

bool PrimLista::ellenoriz(int szam) {
    return primSet.find(szam) != primSet.end();
}

bool PrimLista::isGenerated(int max) {
    return max <= maxGenerated;
}