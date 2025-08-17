#include <iostream>
#include <string>
#include <algorithm>
#include "PrimeFunctions.h"

struct comma_numpunct : std::numpunct<char> {
protected:
  char do_thousands_sep() const override { return ' '; }   // séparateur
  std::string do_grouping() const override { return "\3"; } // tous les 3 chiffres
};

static std::string format_with_commas(long long value) {
  std::string s = std::to_string(value);
  int insertPosition = s.length() - 3;
  while (insertPosition > 0) {
    s.insert(insertPosition, " ");
    insertPosition -= 3;
  }
  return s;
}

int main()
{
    std::cout << "Hello prime numbers\n";
    int n = 1'000'000;
    std::locale loc(std::cout.getloc(), new comma_numpunct);
    std::cout.imbue(loc);

    if (n < 2) {
        std::cout << "There are no prime numbers less than 2.\n";
        return 0;
    }

    std::cout << "Prime numbers up to " << n << ":\n";
    for (int i = 2; i <= n; ++i) {
        if (IsPrime(i)) {
            std::cout << format_with_commas(i) << "\n";
        }
    }
    
    std::cout << "\n";
    return 0;
}
