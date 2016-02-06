#include <cstdio>
#include <cstring>

using namespace std;

bool grid[2000][2000];
bool filled[2000][2000];
int n,m;

int x = 0;

void flood_fill(int i, int j) {
    printf("%d %d\n", i, j);

    if (i < 0 || j < 0) return;
    if (i > 1100 || j > 1100) return;
    if (filled[i][j]) return;
    filled[i][j] = true;

    if (!grid[i][j]) {
        if (i > 0 && grid[i-1][j]) x++;
        if (j > 0 && grid[i][j-1]) x++;
        if (grid[i+1][j]) x++;
        if (grid[i][j+1]) x++;
    }

    if (i > 0) flood_fill(i-1,j);
    if (j > 0) flood_fill(i,j-1);
    flood_fill(i,j+1);
    flood_fill(i+1,j);
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 0; i < 2000; i++) {
        for (int j = 0; j < 2000; j++) {
            grid[i][j] = false;
        }
    }

    for (int i = 0; i < 2000; i++) {
        for (int j = 0; j < 2000; j++) {
            filled[i][j] = false;
        }
    }

    getchar();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char x = getchar();
            printf("%c", x);
            if (x == '1') grid[i][j] = true;
        }
        printf("\n");
        getchar();
    }

    flood_fill(0,0);
    printf("%d\n", x);
}