

#pragma once
#include <chrono>
#include <string>

class Idomero {
    std::chrono::steady_clock::time_point start;
public:
    void indit();
    void kiir(const std::string& prefix = "Eltelt idő: ") const;
};