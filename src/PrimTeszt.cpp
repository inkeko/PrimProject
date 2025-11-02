
#include "PrimTeszt.hpp"
#include <cmath>

bool PrimTeszt::ellenoriz(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;

    int gyok = static_cast<int>(std::sqrt(n));
    for (int i = 3; i <= gyok; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}