#include <cmath>
#include <iostream>
#include "Universe.h"

Universe::Universe() {
    int n;
    interface::InputHandler(n, L"Введите разрядность кодов Грея [0; %]: ", 0, MAX_LENGTH,
                            L"Неверно введена разрядность");
    if (n == 0) throw EmptyUniverse();
    bit_len = n;
    pwr = (int)pow(2, bit_len);
    Fill();
}

Universe::Universe(int n) {
    if (n < 0 || n > MAX_LENGTH) throw WrongBitLen();
    if (n == 0) throw EmptyUniverse();
    bit_len = n;
    pwr = (int)pow(2, bit_len);
    Fill();
}


void Universe::Fill() {
    for (int i = 0; i < pwr; i++)
        muls.push_back(1 + rand() % MAX_MUL);

    std::vector<bool> B(bit_len, 0);
    codes.push_back(B);
    for (int i = 1; i < pwr; i++) {
        B[bit_len - AuxQ(i)] = 1 - B[bit_len - AuxQ(i)];
        codes.push_back(B);
    }
}

void Universe::Out() const {
    for (int i = 0; i < pwr; i++) {
        for (int j = 0; j < bit_len; j++)
            std::wcout << codes[i][j];
        std::wcout << ": " << muls[i] << L'\n';
    }
}

int Universe::get_pwr() const {
    return pwr;
}

int Universe::get_mul(int i) const {
    return muls[i];
}

int Universe::get_bit_len() const {
    return bit_len;
}

int AuxQ(int n) {
    int q = 1, j = n;
    while (j % 2 == 0) {
        j /= 2;
        q++;
    }
    return q;
}
