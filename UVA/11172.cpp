#include <stdio.h>

int main(void) {
    // Standard test_case input
    int test_cases;
    scanf("%d", &test_cases);

    for (int i = 0; i < test_cases; i++) {
        long long a, b;
        scanf("%lld %lld", &a, &b);

        // For each set of numbers inputted, just test
        // if they are greater than, less than, or equal
        // It's a trivial problem, what more can I comment on?

        if (a < b) printf("<\n");
        else if (a > b) printf(">\n");
        else if (a == b) printf("=\n");
    }
}