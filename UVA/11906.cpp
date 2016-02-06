#include <stdio.h>

char map[150][150];
long long counter[150][150];
long long depth_matrix[150][150];
long long rows, columns, water_number;
long long x_move, y_move;

void build_map() {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            map[i][j] = '.';
        }
    }

    for (int i = 0; i < water_number; i++) {
        long long water_x, water_y;
        scanf("%lld %lld", &water_x, &water_y);
        map[water_x][water_y] = 'X';
    }
}

void reset_counter() {
    for (int i = 0; i < 150; i++) {
        for (int j = 0; j < 150; j++) {
            counter[i][j] = 0;
        }
    }
}

void reset_dfs() {
    for (int i = 0; i < 150; i++) {
        for (int j = 0; j < 150; j++) {
            depth_matrix[i][j] = 0;
        }
    }
}

void dfs(long long x, long long y, long long moves[][2], long long move_num) {
    //printf("%d %d\n", x, y);

    depth_matrix[y][x] = 1;

    for (long long i = 0; i < move_num; i++) {
        long long x_move = moves[i][0];
        long long y_move = moves[i][1];

        //printf("%d %d\n", x_move, y_move);

        long long x_pos = x + x_move;
        long long y_pos = y + y_move;

        if (x_pos >= 0 && x_pos < rows
         && y_pos >= 0 && y_pos < columns
         && map[x_pos][y_pos] != 'X') {
            counter[y][x]++;

            //printf("%lld %lld Can reach %lld %lld via %lld %lld\n",
            //   x, y, x_pos, y_pos, x_move, y_move);

            // go down move
            if (depth_matrix[y_pos][x_pos] == 0) dfs(x_pos, y_pos, moves, move_num);
        }
    }
}

int main() {
    long long cases;
    scanf("%lld", &cases);

    for (long long i = 1; i <= cases; i++) {
        scanf("%lld %lld %lld %lld", &rows, &columns, &x_move, &y_move);
        scanf("%lld", &water_number);

        build_map();
        reset_counter();
        reset_dfs();

        if (x_move == 0) {
            long long moves[][2] = {{ 0,        y_move},
                                    { 0,       -y_move},
                                    { y_move,   0     },
                                    {-y_move,   0     }  };
            long long move_num = 4;
            dfs(0, 0, moves, move_num);
        }

        else if (y_move == 0) {
            long long moves[][2] = {{ x_move,   0      },
                                    {-x_move,   0      },
                                    { 0,        x_move },
                                    { 0,       -x_move}  };
            long long move_num = 4;
            dfs(0, 0, moves, move_num);
        }

        else if (x_move == y_move) {
            long long moves[][2] = {{  x_move,   y_move },
                                    { -x_move,   y_move },
                                    {  x_move,  -y_move },
                                    { -x_move,  -y_move }  };
            long long move_num = 4;
            dfs(0, 0, moves, move_num);
        }

        else {
            long long moves[][2] = {{ x_move,   y_move},
                                    { x_move,  -y_move},
                                    {-x_move,  y_move},
                                    {-x_move, -y_move},
                                    { y_move,   x_move},
                                    { y_move,  -x_move},
                                    {-y_move,   x_move},
                                    {-y_move,  -x_move}  };
            long long move_num = 8;
            dfs(0, 0, moves, move_num);
        }

        long long evens = 0, odds = 0;
        for (long long j = 0; j < columns; j++) {
            for (long long k = 0; k < rows; k++) {
                //printf("%lld %lld %lld %lld\n", j, k, depth_matrix[j][k], counter[j][k]);
                if (depth_matrix[j][k] == 1) {
                    if (counter[j][k] % 2 == 0) evens++;
                    else odds++;
                }
            }
        }

        printf("Case %lld: %lld %lld\n", i, evens, odds);
    }
}