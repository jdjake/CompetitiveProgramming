#include <cstdio>

using namespace std;

int main() {
    int test_cases;
    scanf("%d", &test_cases);

    int numgod, nummon;
    for (int i = 0; i < test_cases; i++) {
        int current_max = -100000;
        int current_win = -1;

        scanf("%d %d", &numgod, &nummon);

        int strength;

        for (int j = 0; j < numgod; j++) {
            scanf("%d", &strength);

            if (strength > current_max) {
                current_win = 0;
                current_max = strength;
            }
        }

        for (int j = 0; j < nummon; j++) {
            scanf("%d", &strength);

            if (strength > current_max) {
                current_win = 1;
                current_max = strength;
            }

            //if (strength == current_max) {
            //    if (current_win = 0) current_win = -1;
            //}
        }

        if (current_win == -1) printf("uncertain\n");
        if (current_win == 0) printf("Godzilla\n");
        if (current_win == 1) printf("MechaGodzilla\n");
    }
}