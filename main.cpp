#include <iostream>
#include "Universe.h"
#include "Multiset.h"

int main() {
    srand(time(0));
    setlocale(LC_ALL, "Rus");

    try {
        Universe u;

        std::wcout << L"________________\n";
        std::wcout << L"Universe u\n";
        u.Out();
        std::wcout << L"________________\n";
        std::wcout << L'\n';

        try {
            Multiset gen1(&u), gen2(&u);

            gen1.ChooseMode();
            gen2.ChooseMode();

            std::wcout << L"________________\n";

            Multiset m1 = gen1;
            std::wcout << quote(m1) << L'\n';
            m1.FullOut();
            std::wcout << L"\n________________\n";

            Multiset m2 = gen2;
            std::wcout << quote(m2) << L'\n';
            m2.FullOut();
            std::wcout << L"\n________________\n";

            m1 = gen1, m2 = gen2;
            std::wcout << L"Intersection of " << quote(m1) << " and " << quote(m2) << L'\n';
            m1.Intersection(m2).FullOut();
            std::wcout << L"\n________________\n";

            m1 = gen1, m2 = gen2;
            std::wcout << L"Union of " << quote(m1) << " and " << quote(m2) << L'\n';
            m1.Union(m2).FullOut();
            std::wcout << L"\n________________\n";

            m1 = gen1, m2 = gen2;
            std::wcout << L"Complement of " << quote(m1) << L'\n';
            (!m1).FullOut();
            std::wcout << L"\n________________\n";

            m1 = gen1, m2 = gen2;
            std::wcout << L"Complement of " << quote(m2) << L'\n';
            (!m2).FullOut();
            std::wcout << L"\n________________\n";

            m1 = gen1, m2 = gen2;
            std::wcout << L"Difference between " << quote(m1) << " and " << quote(m2) << L'\n';
            m1.Difference(m2).FullOut();
            std::wcout << L"\n________________\n";

            m1 = gen1, m2 = gen2;
            std::wcout << L"Difference between " << quote(m2) << " and " << quote(m1) << L'\n';
            m2.Difference(m1).FullOut();
            std::wcout << L"\n________________\n";

            m1 = gen1, m2 = gen2;
            std::wcout << quote(m1) << " + " << quote(m2) << L'\n';
            (m1 + m2).FullOut();
            std::wcout << L"\n________________\n";

            m1 = gen1, m2 = gen2;
            std::wcout << quote(m1) << " - " << quote(m2) << L'\n';
            (m1 - m2).FullOut();
            std::wcout << L"\n________________\n";

            m1 = gen1, m2 = gen2;
            std::wcout << quote(m2) << " - " << quote(m1) << L'\n';
            (m2 - m1).FullOut();
            std::wcout << L"\n________________\n";

            m1 = gen1, m2 = gen2;
            std::wcout << L"Symmetric difference between " << quote(m1) << " and " << quote(m2) << L'\n';
            m1.SymmetricDifference(m2).FullOut();
            std::wcout << L"\n________________\n";

            m1 = gen1, m2 = gen2;
            std::wcout << L"Symmetric difference between " << quote(m2) << " and " << quote(m1) << L'\n';
            m2.SymmetricDifference(m1).FullOut();
            std::wcout << L"\n________________\n";

            m1 = gen1, m2 = gen2;
            std::wcout << quote(m1) << " * " << quote(m2) << L'\n';
            (m1 * m2).FullOut();
            std::wcout << L"\n________________\n";

            m1 = gen1, m2 = gen2;
            std::wcout << quote(m1) << " / " << quote(m2) << L'\n';
            (m1 / m2).FullOut();
            std::wcout << L"\n________________\n";

            m1 = gen1, m2 = gen2;
            std::wcout << quote(m2) << " / " << quote(m1) << L'\n';
            (m2 / m1).FullOut();
            std::wcout << L"\n________________\n";
        }
        catch (DifferentUniverses) {
            std::wcout << L"У множеств разные универсумы\n";
        }
    }
    catch(EmptyUniverse) {
        std::wcout << L"Универсум - пустое множество\n";
    }

    system("pause");
    return 0;
}
