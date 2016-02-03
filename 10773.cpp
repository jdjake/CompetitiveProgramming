#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int test_cases;
    scanf("%d", &test_cases);

    for (int i = 1; i <= test_cases; i++) {
        long double d, v, u;
        scanf("%Lf %Lf %Lf", &d, &v, &u);

        if (u == 0 || v == 0 || v >= u) printf("Case %d: can't determine\n", i);
        else {
            long double shortest_time = d/(u*sqrt(1 - v*v/u/u));
            long double fastest_time = d/u;
            printf("Case %d: %.3Lf\n", i, shortest_time - fastest_time);
        }
    }
}