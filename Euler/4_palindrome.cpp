#include <iostream>
#include <string>

bool is_palindrome(long long x) {
    std::string x_string = std::to_string(x);

    for (int i = 0; i < x_string.length(); i++) {
        if (x_string.at(i) != x_string.at(x_string.length() - i - 1)) return false;
    }

    return true;
}

int main() {
    long long biggest = 0;
    for (long long i = 1; i < 1000; i++) {
        for (long long j = 1; j < 1000; j++) {
            if (i*j > biggest && is_palindrome(i*j)) biggest = i*j;
        }
    }

    std::cout << "The biggest number is "
              << biggest
              << "\n";
}