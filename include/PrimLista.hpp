#pragma once
#include <unordered_set>

class PrimLista {
public:
    static void general(int max);
    static bool ellenoriz(int szam);
    static bool isGenerated(int max);
private:
    static std::unordered_set<int> primSet;
    static int maxGenerated;
};