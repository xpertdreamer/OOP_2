#include "abiturient.hpp"
#include "observer.hpp"
#include <ios>
#include <iostream>
#include <ostream>
#include <vector>

#define BAD_SCORE 3.0
#define C(sc) ((sc) < BAD_SCORE)

int main() {
    Abiturient abit_0;
    Abiturient abit_1("Gurin", "Alexej", "Nikolaevich",
                      Address("Penza", "Ternovskogo", 168), {4.2, 4.1, 4.2});
    Abiturient abit_2("Zaharov", "Artem", "Vyachik",
                      Address("Penza", "Ternovskogo", 168), {4.7, 4.8, 4.7});
    Abiturient abit_3("Budnikow", "Alexej", "Sergeevich",
                      Address("Bessonovka", "Tsentralnaya", 312),
                      {5.0, 5.0, 5.0});
    Abiturient abit_4("Ivanov", "Vasiliy", "Vasilievich", {"SPB", "Lenina", 1},
                      {2.7, 3.8, 3.7});
    Abiturient abit_5 = abit_4;
    std::vector abits = {abit_0, abit_1, abit_2, abit_3, abit_4, abit_5};

    std::cout << std::boolalpha;
    std::cout << (abit_4 == abit_5) << std::endl;
    std::cout << (abit_4 != abit_3) << std::endl;

    Observer obs_0(abit_0);
    Observer obs_1(abit_1);
    std::cout << obs_0.GetInfo() << std::endl;
    std::cout << std::endl;
    std::cout << obs_1.GetInfo() << std::endl;

    return 0;
}
