#include <stdio.h>

char map[150][150];
long long x_pos, y_pos, orientation, rows, columns, instruction_number;

void read_map(long long rows, long long columns) {
    // Reads in the map for the robot to move around in.

    for (long long i = 0; i < rows; i++) {
        for (long long j = 0; j < columns; j++) {
            scanf(" %c", &map[i][j]);

            switch(map[i][j]) {
                case 'N' :
                    orientation = 0;
                    break;
                case 'L' :
                    orientation = 1;
                    break;
                case 'S' :
                    orientation = 2;
                    break;
                case 'O' :
                    orientation = 3;
                    break;
                default :
                    continue;
            }

            // This part only occurs when map[i][j] == 'N','L','S', or 'O'
            y_pos = i;
            x_pos = j;
            map[i][j] = '.';
        }
    }
}

long long move_robot() {
    long long stickers = 0;

    char instruction;
    for (long long i = 0; i < instruction_number; i++) {
        scanf(" %c", &instruction);

        switch (instruction) {
            // Turn Right
            case 'D':
                orientation = (orientation + 1) % 4;
                break;

            // Turn Left
            case 'E':
                orientation = (orientation + 3) % 4;
                break;

            // Move forward
            case 'F':
                long long x_move = x_pos, y_move = y_pos;

                switch (orientation) {
                    case 0:
                        y_move = y_pos - 1;
                        break;
                    case 1:
                        x_move = x_pos + 1;
                        break;
                    case 2:
                        y_move = y_pos + 1;
                        break;
                    case 3:
                        x_move = x_pos - 1;
                        break;
                }

                if (y_move >= 0 && y_move < rows
                 && x_move >= 0 && x_move < columns
                 && map[y_move][x_move] != '#') {
                    // If we land on a sticker, we score!
                    if (map[y_move][x_move] == '*') {
                        stickers++;
                        map[y_move][x_move] = '.';
                    }

                    // Now we move into our next position.
                    x_pos = x_move;
                    y_pos = y_move;
                }
        }
    }

    return stickers;
}

int main() {
    scanf("%lld %lld %lld", &rows, &columns, &instruction_number);
    while (rows != 0 || columns != 0 || instruction_number != 0) {
        read_map(rows, columns);
        long long stickers = move_robot();

        //printf("%lld at (%lld %lld)\n", orientation, x_pos, y_pos);

        printf("%d\n", stickers);

        scanf("%lld %lld %lld", &rows, &columns, &instruction_number);
    }
}