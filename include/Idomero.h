

#pragma once
#include <chrono>
#include <string>
#include <iostream>

class Idomero {
    std::chrono::high_resolution_clock::time_point start;
public:
    void indit() {
        start = std::chrono::high_resolution_clock::now();
    }

    void kiir(const std::string& muvelet) {
        auto end = std::chrono::high_resolution_clock::now();
        auto us = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
        std::cout << muvelet << " időtartama: " << us << " μs\n";
    }
};