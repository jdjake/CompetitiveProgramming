#include <stdio.h>

long long graph[80][80];

int main() {
    long long max_x, max_y;
    scanf("%lld %lld", &max_x, &max_y);

    for (long long i = 0; i < 80; i++) {
        for (long long j = 0; j < 80; j++) {
            graph[i][j] = 0;
        }
    }

    long long x_pos, y_pos, robot_direction;
    char facing, instruction;
    while (scanf("%lld %lld %c", &x_pos, &y_pos, &facing) != EOF) {
        switch(facing) {
            case('N'):
                robot_direction = 0;
                break;
            case('E'):
                robot_direction = 1;
                break;
            case('S'):
                robot_direction = 2;
                break;
            case('W'):
                robot_direction = 3;
                break;
        }

        bool is_lost = false;

        scanf("%c", &instruction);
        while (true) {
            if (scanf("%c", &instruction) == EOF) break;
            if (instruction == '\n') break;

            switch(instruction) {
                case('L'):
                    robot_direction = (robot_direction + 3) % 4;
                    //printf("L: Robot is now %lld\n", robot_direction);
                    break;
                case('R'):
                    robot_direction = (robot_direction + 1) % 4;
                    //printf("R: Robot is now %lld\n", robot_direction);
                    break;
                case('F'):
                    if (is_lost) continue;

                    long long move_x, move_y;
                    switch(robot_direction) {
                        // North
                        case (0):
                            move_x = 0;
                            move_y = 1;
                            break;
                        // East
                        case (1):
                            move_x = 1;
                            move_y = 0;
                            break;
                        // South
                        case (2):
                            move_x = 0;
                            move_y = -1;
                            break;
                        // West
                        case (3):
                            move_x = -1;
                            move_y = 0;
                            break;
                    }

                    long long new_x_pos = x_pos + move_x;
                    long long new_y_pos = y_pos + move_y;

                    if ((new_x_pos > max_x || new_y_pos > max_y
                      || new_x_pos < 0 || new_y_pos < 0)
                      && is_lost == false) {
                        if (graph[x_pos][y_pos] == 0) {
                            graph[x_pos][y_pos] = 1;
                            is_lost = true;
                        }
                    }

                    //printf("%lld %lld\n", new_x_pos, new_y_pos);

                    else {
                        x_pos = new_x_pos;
                        y_pos = new_y_pos;
                    }
            }
        }

        char final_direction;

        switch(robot_direction) {
            case (0):
                final_direction = 'N';
                break;
            case (1):
                final_direction = 'E';
                break;
            case (2):
                final_direction = 'S';
                break;
            case (3):
                final_direction = 'W';
                break;
        }

        if (is_lost)
            printf("%lld %lld %c LOST\n", x_pos, y_pos, final_direction);

        else printf("%lld %lld %c\n", x_pos, y_pos, final_direction);
    }
}