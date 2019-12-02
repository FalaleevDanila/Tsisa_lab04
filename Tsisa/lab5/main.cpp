#include <iostream>
#include <windows.h>
#include "functions/functions.hpp"
int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::vector <double> first{1, 4, 3, 7};
    std::vector <double> second{4, 2, 6, 4};
    std::vector <double> third{1, 5, 3, 7};
    std::vector <double> fouth{2, 6, 3, 8};
    limitedCriterialMethod(first, second, third, fouth);
    parettoMethod( first, second, third, fouth);
    weightOfCriteris( first, second, third, fouth);
    analizIerarhij();
    return 0;
}