#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <utility>
#include <vector>

#define LEFT 0
#define RIGHT 1

using namespace std;

int main() {
    int c;
    scanf("%d", &c);

    for (int i = 0; i < c; i++) {
        int n, t, m;
        scanf("%d %d %d", &n, &t, &m);

        queue<int> left;
        queue<int> right;

        vector< pair<int,int> > output;

        for (int j = 0; j < m; j++) {
            int minute;
            char direction[100];
            scanf("%d %s", &minute, &direction);

            if (strcmp(direction, "left") == 0) left.push(minute);
            else if (strcmp(direction, "right") == 0) right.push(minute);
        }

        int current_time = 0;
        bool side = 0;
        while (left.size() > 0 || right.size() > 0) {
            int loading = 0;

            if (side == LEFT) {
                while (left.front() <= current_time && loading < n && left.size() > 0) {
                    output.push_back(make_pair(left.front(), current_time + t));
                    left.pop();
                    loading += 1;
                }
            }

            if (side == RIGHT) {
                while (right.front() <= current_time && loading < n && right.size() > 0) {
                    output.push_back(make_pair(right.front(), current_time + t));
                    right.pop();
                    loading += 1;
                }
            }

            if (loading > 0) {
                side = !side;
                current_time += t;
            }
        }

        for (auto i : output) {
            printf("%d %d\n", i.first, i.second);
        }

        printf("\n");
    }
}