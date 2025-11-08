
#include <iostream>
#include "PrimTeszt.hpp"
#include "utils/Idomero.hpp"
#include "PrimLista.hpp"
#include "SzitaGenerator.hpp"
#include "SIMDSzita.hpp"
#include "utils/input.hpp"
#include "utils/wait.hpp"
#ifdef _WIN32
#include <Windows.h>
#endif


int main() {
// Magyar karakterek konzolra
    SetConsoleOutputCP(65001);
    long long szam = readPositiveLong();



    const int KIS_SZAM_KUSZOB = 10000;



    std::cout << "\nVálaszd ki az ellenőrzési módszert:\n";
    std::cout << "1 - Egyszerű osztókeresés (PrimTeszt)\n";
    std::cout << "2 - Prímkeresés előre generált listából (PrimLista)\n";
    std::cout << "3 - Eratoszthenész szita (SzitaGenerator)\n";
    std::cout << "4 - SIMD optimalizált szita (SIMDSzita)\n";
    
    std::cout << "\nAjánlás: ";
    if (szam <= KIS_SZAM_KUSZOB) {
    std::cout << "1 vagy 2 (gyorsabb kis számokra)\n";
     } else {
    std::cout << "3 vagy 4 (hatékonyabb nagy számokra)\n";
     }
      std::cout << "Módszer száma: ";

   int valasztas = readMenuChoice(1, 4);

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
         case 4:
         ido.indit();
         {
             SIMDSzita szita(2, szam); // alsó határ fixen 2, felső a megadott szám
             szita.futtat();
             szita.kiir(); 
             // Ellenőrzés: ha szam prím, akkor szita[ (szam - 1)/2 ] == 1
        if (szam == 2) {
            eredmeny = true;
        } else if (szam % 2 == 0 || szam < 2) {
            eredmeny = false;
        } else {
            int index = (szam - 1) / 2;
            eredmeny = szita.isPrim(szam);
        }


        
            }
              ido.kiir("SIMDSzita");
    break;
        default:
            std::cout << "Érvénytelen választás.\n";
            return 1;
    }

    std::cout << "\nA(z) " << szam << (eredmeny ? " prím.\n" : " nem prím.\n");
     waitForExit();

    return 0;
}