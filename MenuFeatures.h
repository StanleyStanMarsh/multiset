#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cstdarg>
#include <conio.h>

#define quote(x) #x

namespace interface {
    template <typename T> inline std::wstring format(std::wstring msg, int n_args, ...) {
        va_list ap;
        va_start(ap, n_args);
        std::wstring str_new = msg;
        while (str_new.find('%') != std::string::npos) {
            str_new.replace(str_new.find('%'), 1, std::to_wstring(va_arg(ap, T)));
        }
        va_end(ap);
        return str_new;
    }

    inline void WrongInput(std::wstring s) {
        std::wcin.clear();
        while (std::wcin.get() != '\n');
        std::wcerr << s << L'\n';
    }

    inline void InputHandler(int &n, std::wstring msg, int min, int lim, std::wstring err) {
        while (true) {
            std::wcout << format<long long>(msg, 1, lim);
            std::wcin >> n;
            if (n >= min && n <= lim && !std::wcin.fail() && std::wcin.peek() == '\n') break;
            else interface::WrongInput(err);
        }
    }
}