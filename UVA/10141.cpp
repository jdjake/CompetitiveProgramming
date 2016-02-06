#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <math.h>

char* requirements[1050];

int main() {
    for (int i = 0; i < 1000; i++) requirements[i] = (char*) malloc(200);

    int n,p;
    int a = 1;
    int c = 0;
    while (scanf("%d %d\n", &n, &p), (n != 0 || p != 0)) {
        for (int i = 0; i < n; i++) scanf("%[^\n]\n", requirements[i]);
        //for (int i = 0; i < n; i++) printf("Requirement: %s\n", requirements[i]);

        char bestproposal[100];
        int best_met = 0;
        double bestcost = INFINITY;

        char proposal[100];
        double d;
        int r;
        for (int i = 0; i < p; i++) {
            scanf("%[^\n]\n", proposal);
            scanf("%lf %d\n", &d, &r);

            int num_met = 0;
            for (int j = 0; j < r; j++) {
                scanf("%*[^\n]\n", met);

                for (int k = 0; k < n; k++) {
                    if (strcmp(requirements[k], met) == 0) {
                        //printf("%s met %s\n", proposal, met);
                        num_met++;
                        break;
                    }
                }
            }

            if (r > best_met || (r == best_met && bestcost > d)) {
                strcpy(bestproposal, proposal);
                bestcost = d;
                best_met = num_met;
            }
        }

        if (c == 1) printf("\n");
        printf("RFP #%d\n", a);
        printf("%s\n", bestproposal);

        a++;
        c = 1;
    }
}