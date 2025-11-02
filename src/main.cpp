
#include <iostream>
#include "PrimTeszt.h"
#include "Idomero.h"
#include "PrimLista.h"
#include "SzitaGenerator.h"

// #include "SzitaGenerator.h" // majd később aktiváljuk

int main() {
    int szam;
    std::cout << "Adj meg egy számot, amit ellenőrizni szeretnél: ";
    std::cin >> szam;

    std::cout << "\nVálaszd ki az ellenőrzési módszert:\n";
    std::cout << "1 - Egyszerű osztókeresés (PrimTeszt)\n";
    std::cout << "2 - Prímkeresés előre generált listából (PrimLista)\n";
    std::cout << "3 - Eratoszthenész szita (SzitaGenerator)\n";
    std::cout << "Módszer száma: ";

    int valasztas;
    std::cin >> valasztas;

    Idomero ido;
    bool eredmeny = false;

    switch (valasztas) {
        case 1:
            ido.indit();
            eredmeny = PrimTeszt::ellenoriz(szam);
            ido.kiir("PrimTeszt");
            break;
        case 2:
    if (!PrimLista::isGenerated(szam)) {
        ido.indit();
        PrimLista::general(szam);
        eredmeny = PrimLista::ellenoriz(szam);
        ido.kiir("PrimLista (generálással)");
    } else {
        ido.indit();
        eredmeny = PrimLista::ellenoriz(szam);
        ido.kiir("PrimLista (csak keresés)");
    }
    break;
        case 3:
    if (!SzitaGenerator::isGenerated(szam)) {
        ido.indit();
        SzitaGenerator::general(szam);
        eredmeny = SzitaGenerator::ellenoriz(szam);
        ido.kiir("SzitaGenerator (generálással)");
    } else {
        ido.indit();
        eredmeny = SzitaGenerator::ellenoriz(szam);
        ido.kiir("SzitaGenerator (csak keresés)");
    }
    break;
        default:
            std::cout << "Érvénytelen választás.\n";
            return 1;
    }

    std::cout << "\nA(z) " << szam << (eredmeny ? " prím.\n" : " nem prím.\n");
    return 0;
}