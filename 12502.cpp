#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int test_cases;
    scanf("%d", &test_cases);

    for (int i = 0; i < test_cases; i++) {
        int x,y,z;
        scanf("%d %d %d", &x, &y, &z);

        int paid = z*(2*x - y)/(x + y);
        printf("%d\n", paid);
    }
}