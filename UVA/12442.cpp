#include <iostream>
#include <cstdio>

using namespace std;

int best[60000];
bool seen[60000];
int next[60000];

// Compute best length for x
int dfs(int x) {
    if (best[x] != -1) return best[x];
    if (seen[x] == false) return 0;

    else {
        seen[x] = true;

        next_x = next[x];
        int next_best = dfs(next_x);

        // If x in cycle
        if (best[j] != -1) best[x] = next_best;

        // else if x not in cycle
        else best[x] = next_best + 1;
    }
}

void run_program() {
    int martian_number;
    scanf("%d", &martian_number);

    for (int j = 0; j < martian_number; j++) {
        int martian;
        int martian_connected;
        scanf("%d %d", martian, martian_connected);
        next[martian] = martian_connected;
    }

    for (int j = 0; j < martian_number; j++) dfs(j);
}

int main() {
    int test_cases;
    scanf("%d", &test_cases);

    for (int i = 1; i <= test_cases; i++) {
        for (int j = 0; j < 60000; j++) best[j] = -1;

        int best = run_program();
        printf("Case %d: %d\n", i, best);
    }
}