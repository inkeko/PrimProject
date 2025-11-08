

#pragma once
#include <chrono>
#include <string>
#include <iostream>

class Idomero {
    std::chrono::steady_clock::time_point start;
public:
    void indit() {
        start = std::chrono::steady_clock::now();
    }

    void kiir(const std::string& prefix ="Eltelt idő: ") const  {
        auto end = std::chrono::steady_clock::now();
         auto us = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        long long ms = us.count();

        long long seconds = ms / 1000;
        long long minutes = seconds / 60;
        seconds %= 60;
        ms %= 1000;

        std::cout << prefix;
        if (minutes > 0) std::cout << minutes << " perc ";
        std::cout << seconds << " másodperc ";
        std::cout << ms << " milliszekundum\n";


        
    }
};