#ifndef INPUT_UTILS_HPP
#define INPUT_UTILS_HPP

#include <iostream>
#include <limits>
#include <string>
#include <sstream>

long long readPositiveLong() {
    std::string input;
    long long szam = 0;

    while (true) {
        std::cout << "Adj meg egy pozitív egész számot: ";
        std::getline(std::cin, input);

        std::stringstream ss(input);
        if (ss >> szam && !(ss >> input) && szam > 0) {
            return szam;
        }

        std::cout << "Hibás bemenet! Csak pozitív egész számot adj meg.\n";
    }
}

inline int readMenuChoice(int min, int max) {
    std::string input;
    int valasztas = 0;

    while (true) {
        std::cout << "Módszer száma (" << min << "–" << max << "): ";
        std::getline(std::cin, input);

        std::stringstream ss(input);
        if (ss >> valasztas && !(ss >> input) && valasztas >= min && valasztas <= max) {
            return valasztas;
        }

        std::cout << "Hibás választás! Csak " << min << " és " << max << " közötti számot adj meg.\n";
    }
}

#endif