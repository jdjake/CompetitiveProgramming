#include <cstdio>

using namespace std;

int main() {
    int test_cases;
    scanf("%d", &test_cases);

    for (int i = 1; i <= test_cases; i++) {
        int N,K,P;
        scanf("%d %d %d", &N, &K, &P);

        int output = (K - 1 + P) % N;
        printf("Case %d: %d\n", i, output + 1);
    }
}