#pragma once

#include "Universe.h"

class DifferentUniverses : public std::exception {
    const char* reason;
public:
    DifferentUniverses() : reason("Multisets have different Universes") {}
    [[nodiscard]] const char* what() const noexcept override { return reason; }
};

class Multiset {
    Universe *uni;
    std::vector<int> set_muls; // Multiplicities
public:
    explicit Multiset(Universe* u) : uni(u) { set_muls.resize(uni->get_pwr()); }
    Multiset(const Multiset &mset);

    void AutoFill();
    void ManualFill();
    void Out() const;
    void FullOut() const;
    void ChooseMode();

    Multiset &operator!();
    Multiset &Intersection(Multiset &other);
    Multiset &Union(Multiset &other);
    Multiset &Difference(Multiset &other);
    Multiset &operator+(Multiset &other);
    Multiset &operator-(Multiset &other);
    Multiset &SymmetricDifference(Multiset &other);
    Multiset &operator*(Multiset &other);
    Multiset &operator/(Multiset &other);
};
