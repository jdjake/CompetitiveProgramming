#include <iostream>

long long largest_prime_factor(long number) {
    long long divisor = 2;
    while (number != 1) {
        if (number % divisor == 0) number /= divisor;
        else                       divisor++;
    }

    return divisor;
}

int main() {
    long long number;
    std::cin  >> number;

    std::cout << "The largest prime factor of "
              << number
              << " is "
              << largest_prime_factor(number)
              << "\n";
}