#include <cstdio>
#include <iostream>

#define RANGE 10000000

using namespace std;

long long counter[RANGE];

long long sequence_count(long long i) {
    if (i > 0 && i < RANGE && counter[i] != -1) return counter[i];
    if (i == 1) return 1;
    if (i % 2 == 0) {
        int output = 1 + sequence_count(i/2);
        if (i < RANGE) counter[i] = output;
        return output;
    }
    else {
        int output = 1 + sequence_count(3*i + 1);
        if (i < RANGE) counter[i] = output;
        return output;
    }
}

long long min(long long a, long long b) {
    if (a < b) return a;
    else return b;
}

long long max(long long a, long long b) {
    if (a > b) return a;
    else return b;
}

int main() {
    for (long long i = 0; i < RANGE; i++) counter[i] = -1;

    long long L,H;
    while (true) {
        scanf("%lld %lld", &L, &H);
        if (L == 0 && H == 0) break;

        long long lower = min(L,H);
        long long higher = max(L,H);
        L = lower;
        H = higher;

        long long longest_value = 0;
        long long longest = 0;
        for (long long i = L; i <= H; i++) {
            long long length;
            if (i % 2 == 0) length = sequence_count(i/2);
            else length = sequence_count(3*i + 1);

            if (length > longest) {
                longest = length;
                longest_value = i;
            }
        }

        printf("Between %lld and %lld, %lld generates the longest sequence of %lld values.\n", L, H, longest_value, longest);
    }
}