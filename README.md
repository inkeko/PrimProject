📄 README.md – PrimProjekt

# PrimProjekt

Hatékony prímszámkereső rendszer C++ nyelven, moduláris felépítéssel. A cél különböző algoritmusok összehasonlítása sebesség és hatékonyság alapján, az `int` tartományban.

## 🎯 Célkitűzés

- Prímszámok keresése különböző módszerekkel
- Időmérés minden algoritmusnál
- Moduláris, jól dokumentált kódszerkezet
- STL használata, osztályokra bontás

## 🧱 Modulok

| Osztály         | Feladat                                      |
|-----------------|-----------------------------------------------|
| `PrimTeszt`     | Egy adott számról eldönti, hogy prím-e        |
| `PrimLista`     | Prímek generálása listába, ellenőrzéshez      |
| `SzitaGenerator`| Eratoszthenész szita implementáció            |
| `Idomero`       | Időmérés minden algoritmusnál                 |
| `Main`          | Belépési pont, vezérlés, tesztelés            |

## 🚀 Fordítás és futtatás

```bash
g++ src/main.cpp src/PrimTeszt.cpp src/Idomero.cpp -o primprojekt
./primprojekt


⏱ Időmérés

Minden algoritmus futása előtt és után időmérés történik az  osztály segítségével:
Idomero ido;
ido.indit();
// algoritmus futtatása
ido.kiir("PrimTeszt");

📂 Verziókövetés

A .gitignore fájl kizárja:
•  .vscode/  – VS Code beállítások
• 	*.exe – bináris fájlok
• 	*.txt – ideiglenes fájlok


📜 Licenc

Ez a projekt szabadon felhasználható, módosítható és terjeszthető nem kereskedelmi célokra, különösen oktatási és tanulási célból.
Részletek: LICENSE.txt

👤 Szerző

Fejlesztő: Csaba (inkeko)
GitHub: github.com/inkeko
