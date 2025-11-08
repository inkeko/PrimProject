#pragma once
#include <iostream>

inline void waitForExit() {
    std::cout << "\nNyomj egy gombot a kilépéshez...\n";
    std::cin.ignore();
    std::cin.get();
}