#pragma once
#include <vector>

class SzitaGenerator {
public:
    static void general(int max);
    static bool ellenoriz(int szam);
    static bool isGenerated(int szam);

private:
    static std::vector<bool> szita;
    static int maxSzam;
};