#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count_flood(vector<string>& grid, int x, int y, char from, char to) {
    if (grid[x][y] != from) return 0;

    vector<int> moves_x {-1,0,1};
    vector<int> moves_y {-1,0,1};

    grid[x][y] = to;

    int total = 1;
    for (auto x_move: moves_x) {
        for (auto y_move: moves_y) {
            total += count_flood(grid, x + x_move, y + y_move, from, to);
        }
    }

    return total;
}

int find_cluster(vector<string> grid) {
    int maximum = 0;

    for (int x = 0; x < grid.size(); x++) {
        for (int y = 0; y < grid.size(); y++) {
            vector<string> grid_2 = grid;
            maximum = max(count_flood(grid_2, x, y, '1', '0'), maximum);
        }
    }

    return maximum;
}

int main() {
    int cases;

    cin >> cases;

    for (int cased = 0; cased < cases; cased++) {
        vector<string> grid;

        string x;
        cin >> x;
        grid.push_back(x);

        for (int k = 1; k < grid[0].size(); k++) {
            string y;
            cin >> y;
            grid.push_back(y);
        }

        cout << find_cluster(grid) << endl;
    }
}