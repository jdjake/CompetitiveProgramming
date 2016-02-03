#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int marbles[15000];

int main() {
    int marble_num, query_num;
    int case_num = 1;
    while (true) {
        scanf("%d %d", &marble_num, &query_num);
        if (marble_num == 0 && query_num == 0) break;

        printf("CASE# %d:\n", case_num);

        for (int i = 1; i <= marble_num; i++) scanf("%d", &marbles[i]);
        sort(marbles + 1, marbles + marble_num + 1);

        int query;
        for (int i = 0; i < query_num; i++) {
            scanf("%d", &query);

            bool found = false;
            for (int j = 1; j <= marble_num; j++) {
                if (marbles[j] == query) {
                    printf("%d found at %d\n", query, j);
                    found = true;
                    break;
                }
            }
            if (!found) printf("%d not found\n", query);
        }

        case_num++;
    }
}