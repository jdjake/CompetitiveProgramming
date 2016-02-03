#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int test_cases;
    scanf("%d", &test_cases);

    for (int i = 0; i < test_cases; i++) {
        long long n;
        scanf("%lld", &n);

        long long lower = 0;
        long long upper = 2000000000;
        while (lower < upper) {
            long long k = upper/2 + lower/2;
            //printf("%lld -> %lld : %lld = %lld : %lld\n", lower, upper, k, k*(k+1), n);

            long long estimate;
            if (k % 2 == 0) estimate = (k/2)*(k + 1);
            else estimate = k*((k + 1)/2);

            if (estimate > n) upper = k;
            else lower = k + 1;
        }

        printf("%lld\n", lower - 1);
    }
}