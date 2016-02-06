#include <iostream>
#include <cstdio>

using namespace std;

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

int main() {
    int grid_size;
    while (true) {
        scanf("%d", &grid_size);
        if (grid_size == 0) break;

        int count = 0;
        for (int i = 0; i < grid_size; i++) {
            for (int j = 0; j < grid_size; j++) {
                count += (grid_size - max(i,j));
            }
        }

        printf("%d\n", count);
    }
}