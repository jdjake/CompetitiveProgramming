#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

int group[200];
int count[20];

int main() {
    int group_size;
    scanf("%d", &group_size);

    for (int i = 0; i < 10; i++) count[i] = 0;
    for (int i = 0; i < group_size; i++) {
        scanf("%d", &group[i]);
        count[group[i]]++;
    }

    int winner = -1;
    for (int i = 6; i > 0; i--) {
        if (count[i] == 1) {
            for (int j = 0; j < group_size; j++) {
                if (group[j] == i) {
                    winner = j;
                    break;
                }
            }

            break;
        }
    }

    if (winner == -1) printf("none\n");
    else printf("%d\n", winner+1);
}