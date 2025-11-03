#pragma once
#include <vector>
#include <string>

class SIMDSzita {
public:
    SIMDSzita(int also = 2, int felso = 1000000);
    void futtat(); // elindítja a szita algoritmust
    void kiir() const; // kiírja a prímeket vagy statisztikát
    bool isPrim(int szam) const;


private:
    int alsoHatar;
    int felsoHatar;
    std::vector<char> szita; // csak páratlan számokat tárolunk
    void inicializal(); // feltölti a szitát 1-esekkel
    void szital(); // többszálú, SIMD-es kinullázás
};