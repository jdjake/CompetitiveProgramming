#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    printf("PERFECTION OUTPUT\n");
    while (true) {
        long long x;
        scanf("%d", &x);
        if (x == 0) break;

        long long divisor_sum = 0;
        for (int i = 1; i < x; i++) {
            if (x % i == 0) divisor_sum += i;
        }

        if (divisor_sum < x) printf("%5d  DEFICIENT\n", x);
        else if (divisor_sum == x) printf("%5d  PERFECT\n", x);
        else printf("%5d  ABUNDANT\n", x);
    }
    printf("END OF OUTPUT\n");
}