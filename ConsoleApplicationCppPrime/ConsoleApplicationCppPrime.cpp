#include <iostream>
#include "PrimeFunctions.h"

int main()
{
    std::cout << "Hello prime numbers\n";
    int n = 255;
    
    if (n < 2) {
        std::cout << "There are no prime numbers less than 2.\n";
        return 0;
    }

    std::cout << "Prime numbers up to " << n << ":\n";
    for (int i = 2; i <= n; ++i) {
        if (IsPrime(i)) {
            std::cout << i << " ";
        }
    }
    
    std::cout << "\n";
    return 0;
}
