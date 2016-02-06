#include <iostream>

long long sum_even_fibonacci(long long range) {
    long long first = 1;
    long long second = 1;

    long long sum = 0;
    while (first <= range) {
        if (first % 2 == 0) {
            sum += first;
        }

        long long temp = second;
        second = first + second;
        first = temp;
    }

    return sum;
}

int main() {
    long long range;
    std::cin  >> range;

    std::cout << "The sum of even fibonacci numbers from 1 to "
              << range
              << " is "
              << sum_even_fibonacci(range)
              << "\n";
}