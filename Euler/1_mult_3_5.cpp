#include <iostream>

long long sum_multiples_3_5(long range_to) {
    long long sum = 0;

    for (int i = 1; i <= range_to; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    return sum;
}

int main() {
    long long range;
    std::cin  >> range;

    std::cout << "The sum of multiples of 3 and 5 from 1 to "
              << range
              << " is "
              << sum_multiples_3_5(range)
              << "\n";
}