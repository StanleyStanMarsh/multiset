#include <iostream>
#include <set>
#include <algorithm>
#include "Multiset.h"

Multiset::Multiset(const Multiset &mset) {
    uni = mset.uni;
    set_muls = mset.set_muls;
}

void Multiset::AutoFill() {
    int n;

    interface::InputHandler(n, L"Введите мощность мультимножества (максимально возможное число %): ",
                            1, uni->get_pwr(), L"Неверно введена мощность");

    if (n == uni->get_pwr()) {
        for (int i = 0; i < uni->get_pwr(); i++)
            set_muls[i] = 1 + rand() % uni->get_mul(i);
        return;
    }

    std::set<int> rands;
    for (int i = 0; i < n; i++) {
        int k;
        do {
            k = rand() % uni->get_pwr();
        } while (rands.contains(k));
        rands.insert(k);
    }

    std::fill(set_muls.begin(), set_muls.end(), 0);
    for (auto c : rands)
        set_muls[c] = 1 + rand() % uni->get_mul(c);
}

void Multiset::ManualFill() {
    std::wcout << L"Введите кратность каждого элемента мультимножества\n";

    for (int i = 0; i < uni->get_pwr(); i++) {
        int n;
        for (int j = 0; j < uni->get_bit_len(); j++)
                std::wcout << uni->codes[i][j];
        interface::InputHandler(n, L" (максимальная кратность %): ", 1, uni->get_mul(i),
                                L"Неверно введена кратность");

        set_muls[i] = n;
    }
}

void Multiset::Out() const {
    for (int i = 0; i < uni->get_pwr(); i++) {
        if (set_muls[i] != 0) {
            for (int j = 0; j < uni->get_bit_len(); j++)
                std::wcout << uni->codes[i][j];
            std::wcout << ": " << set_muls[i] << L'\n';
        }
    }
}

void Multiset::FullOut() const {
    for (int i = 0; i < uni->get_pwr(); i++) {
        for (int j = 0; j < uni->get_bit_len(); j++)
            std::wcout << uni->codes[i][j];
        std::wcout << ": " << set_muls[i] << L'\n';
    }
}

void Multiset::ChooseMode() {
    int key;
    std::wcout << L"Выберите режим заполнения мультимножества m1\n 1. Ручной ввод\n 2. Автоматическое заполнение\n";
    for(;;) {
        key = getch();
        switch (key) {
            case '1':
                ManualFill();
                goto finish_loop;
            case '2':
                AutoFill();
                goto finish_loop;
            default:
                break;
        }
    }
    finish_loop:
    std::wcout << L'\n';
}

Multiset &Multiset::Intersection(Multiset &other) {
    if (uni != other.uni) {
        throw DifferentUniverses();
    }
    for (int i = 0; i < set_muls.size(); i++)
        this->set_muls[i] = std::min(set_muls[i], other.set_muls[i]);
    return *this;
}

Multiset &Multiset::Union(Multiset &other) {
    if (uni != other.uni) {
        throw DifferentUniverses();
    }
    for (int i = 0; i < set_muls.size(); i++)
        this->set_muls[i] = std::max(set_muls[i], other.set_muls[i]);
    return *this;
}

Multiset &Multiset::operator!() {
    for (int i = 0; i < set_muls.size(); i++)
        this->set_muls[i] = uni->get_mul(i) - set_muls[i];
    return *this;
}

Multiset &Multiset::Difference(Multiset &other) {
    if (uni != other.uni) {
        throw DifferentUniverses();
    }
    return this->Intersection(!other);
}

Multiset &Multiset::operator+(Multiset &other) {
    if (uni != other.uni) {
        throw DifferentUniverses();
    }
    for (int i = 0; i < set_muls.size(); i++)
        this->set_muls[i] = std::min(set_muls[i] + other.set_muls[i], uni->get_mul(i));
    return *this;
}

Multiset &Multiset::operator-(Multiset &other) {
    if (uni != other.uni) {
        throw DifferentUniverses();
    }
    for (int i = 0; i < set_muls.size(); i++)
        this->set_muls[i] = std::max(set_muls[i] - other.set_muls[i], 0);
    return *this;
}

Multiset &Multiset::SymmetricDifference(Multiset &other) {
    if (uni != other.uni) {
        throw DifferentUniverses();
    }
    for (int i = 0; i < set_muls.size(); i++)
        this->set_muls[i] = abs(set_muls[i] - other.set_muls[i]);
    return *this;
}

Multiset &Multiset::operator*(Multiset &other) {
    if (uni != other.uni) {
        throw DifferentUniverses();
    }
    for (int i = 0; i < set_muls.size(); i++)
        this->set_muls[i] = std::min(set_muls[i] * other.set_muls[i], uni->get_mul(i));
    return *this;
}

Multiset &Multiset::operator/(Multiset &other) {
    if (uni != other.uni) {
        throw DifferentUniverses();
    }
    for (int i = 0; i < set_muls.size(); i++) {
        if (other.set_muls[i] == 0)
            this->set_muls[i] = 0;
        else
            this->set_muls[i] = set_muls[i] / other.set_muls[i];
    }
    return *this;
}

