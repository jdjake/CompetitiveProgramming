#include <iostream>
#include <cstdio>
#include <vector>
#include <cctype>

using namespace std;

vector<int> adj[30];
bool lit[30];

void resetmaze() {
    for (int i = 0; i < 28; i++) adj[i].clear();
    for (int i = 0; i < 28; i++) lit[i] = false;
}

void simulate(int minotaur, int theseus, int k) {
    int epoch = 0;
    int last_place = theseus;
    int current = minotaur;

    while(true) {
        //printf("%c -> %c : %d\n", last_place + 'A', current + 'A', epoch);

        if (epoch % k == 0 && epoch != 0) {
            printf("%c ", last_place + 'A');
            lit[last_place] = true;
        }
        int next_place = -1;
        for (int i : adj[current]) {
            if (i != last_place && !lit[i]) {
                next_place = i;
                break;
            }
        }

        if (next_place == -1) {
            printf("/%c", current + 'A');
            break;
        }

        epoch += 1;
        last_place = current;
        current = next_place;
    }
    printf("\n");
}

int main() {
    while (true) {
        char nextchar = ' ';
        while (isspace(nextchar)) scanf("%c", &nextchar);
        if (nextchar == '#') break;

        resetmaze();

        char current_root = nextchar;
        while(true) {
            scanf("%c", &nextchar);
            if (nextchar == '.') break;
            if (isspace(nextchar)) continue;
            if (nextchar == ':') continue;
            if (nextchar == ';') scanf("%c", &current_root);
            else (adj[current_root - 'A'].push_back(nextchar - 'A'));
        }

        char minotaur_start, theseus_start;
        int k;
        scanf(" %c %c %d", &minotaur_start, &theseus_start, &k);

        //
        /*
        for (int i = 0; i < 26; i++) {
            printf("%c: ", i + 'A');
            for (int x: adj[i]) printf("%c, ", x + 'A');
            printf("\n");
        }

        printf("Minotaur: %c\n", minotaur_start);
        printf("Theseus: %c\n", theseus_start);
        printf("k: %d\n", k);
        */
        //

        simulate(minotaur_start - 'A', theseus_start - 'A', k);
    }
}