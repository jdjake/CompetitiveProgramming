#include <iostream>
#include <cstdio>

// Number divisible by D is:
//     Pick first number, pick one less, %D = D - first % D

// DP TAble: D[A][B][C]: picking from Ath number onward, how many ways can we pick B numbers such that % D,
// they are equal to C.

// D[A][B][C]:
//    if (A == N): 0
//    if (B == 0): 0
//    else: D[A + 1][B - 1][C + P[A] % D] + D[A + 1][B][C]

int P[300];
long long D[300][20][30];
int N, Q, mod;

void reset_D() {
    for (int i = 0; i < 300; i++) {
        for (int j = 0; j < 20; j++) {
            for (int k = 0; k < 30; k++) D[i][j][k] = -1;
        }
    }
}

long long compute_subsets(int A, int B, int C) {
    if (A > -1 && D[A][B][C] != -1) return D[A][B][C];
    if (B == 0 && C == 0) return 1;
    if (B == 0 && C != 0) return 0;
    if (A == -1) return 0;
    D[A][B][C] = compute_subsets(A - 1, B - 1, (((C + P[A]) % mod) + mod) % mod) + compute_subsets(A - 1, B, C);
    return D[A][B][C];
}

int main() {
    int test_cases = 1;
    while (true) {
        scanf("%d %d", &N, &Q);
        if (N == 0 && Q == 0) break;
        printf("SET %d:\n", test_cases);

        for (int i = 0; i < N; i++) scanf("%d", &P[i]);
        for (int i = 1; i <= Q; i++) {
            int M;
            scanf("%d %d", &mod, &M);
            reset_D();

            long long output = compute_subsets(N-1,M,0);
            printf("QUERY %d: %lld\n", i, output);
        }

        test_cases++;
    }
}