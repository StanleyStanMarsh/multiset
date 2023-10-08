#pragma once

#include "MenuFeatures.h"

const int MAX_MUL = 20; // Max multiplicity
const int MAX_LENGTH = 10; // Max length of Gray code

class WrongBitLen : public std::exception {
    const char* reason;
public:
    WrongBitLen() : reason("Wrong Gray code length number") {}
    [[nodiscard]] const char* what() const noexcept override { return reason; }
};

class EmptyUniverse : public std::exception {
    const char* reason;
public:
    EmptyUniverse() : reason("Universe is empty") {}
    [[nodiscard]] const char* what() const noexcept override { return reason; }
};

class Universe {
    int bit_len; // Gray code capacity
    int pwr; // Cardinality
    std::vector<int> muls; // Vector of multiplicities
public:
    std::vector<std::vector<bool>> codes; // Vector of Gray codes
    Universe();
    Universe(int n);
    void Out() const;
    int get_pwr() const;
    int get_mul(int i) const;
    int get_bit_len() const;

    void Fill();
};

int AuxQ(int n);