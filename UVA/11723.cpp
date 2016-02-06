#include <cstdio>

using namespace std;

int main() {
    int R,D;
    int case_number = 1;
    while ( scanf("%d %d", &R, &D) ) {
        if (R == 0 && D == 0) break;
        bool did_it = false;
        for (int i = 0; i <= 26; i++) {
            if ((i + 1)*D >= R) {
                did_it = true;
                printf("Case %d: %d\n", case_number, i);
                case_number++;
                break;;
            }
        }

        if (!did_it) {
            printf("Case %d: impossible\n", case_number);
            case_number ++;
        }
    }
}