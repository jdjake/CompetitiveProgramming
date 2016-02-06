#include <iostream>
#include <cstdio>

using namespace std;

int x_direction[] = {-1, 0, 1, 0};
int y_direction[] = {0, -1, 0, 1};

int x_increment[] = {1, 0, -1, 0};
int y_increment[] = {0, 1, 0, -1};

int x_start[] = {0, 0, 3, 0};
int y_start[] = {0, 0, 0, 3};

int board[4][4];
bool has_combined[4][4];

void print() {
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
        printf("%d:%d", board[i][j], has_combined[i][j]);
        if (i != 3) printf(" ");
        }
        printf("\n");
    }
}

int main() {
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            scanf("%d", &board[i][j]);
            has_combined[i][j] = 0;
        }
    }

    int direction;
    scanf("%d", &direction);

    int i = 0;
    int x = x_start[direction];
    while (i < 4) {
        i++;
        int j = 0;
        int y = y_start[direction];
        while (j < 4) {
            print();
            j++;

            int new_i = x;
            int new_j = y;
            int current_number = board[x][y];

            // Move next piece
            do {
                new_i += x_direction[direction];
                new_j += y_direction[direction];
                if (new_i < 0 || new_i >= 4 || new_j < 0 || new_j >= 4) break;
            } while(board[new_i][new_j] == 0);

            printf("AIDJ: %d %d %d %d\n", x, new_i, y, new_j);

            if (new_i < 0 || new_i >= 4 || new_j < 0 || new_j >= 4) {
                board[new_i - x_direction[direction]][new_j - y_direction[direction]] = current_number;
                continue;
            }
            else if ((x != new_i || y != new_j) && board[new_i][new_j] == board[x][y] && has_combined[new_i][new_j] != 1) {
                board[new_i][new_j] = board[new_i][new_j]*2;
                has_combined[new_i][new_j] = 1;
                board[x][y] = 0;
            }
            else {
                board[new_i - x_direction[direction]][new_j - y_direction[direction]] = current_number;
                if (new_i - x_direction[direction] != x || new_j - y_direction[direction] != y) board[x][y] = 0;
            }

            y += y_increment[direction];
        }

        x += x_increment[direction];
    }

    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            printf("%d:%d", board[i][j], has_combined[i][j]);
            if (i != 3) printf(" ");
        }
        printf("\n");
    }
}