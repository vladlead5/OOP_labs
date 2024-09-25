#include <iostream>
#include "isCleanNumber.h"

int main() {
    int number;
    std::cout << "Введите число: ";
    std::cin >> number;
    if (isCleanNumber(number)) {
        std::cout << "Число чистое" << std::endl;
    } else {
        std::cout << "Число не является чистым" << std::endl;
    }
    return 0;
}
