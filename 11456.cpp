#include <cstdio>
#include <algorithm>
#include <map>
#include <utility>
#include <tuple>

#define LIMIT 2200

using namespace std;

int n;
int car_weights[LIMIT];

map< pair< int, int>, int > lis;
map< pair< int, int>, int > lds;

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int lisequence(int k, int lower) {
    if (k == n) return 0;
    if (lis.count(make_pair(k, lower))) return lis[make_pair(k,lower)];

    int answer = lisequence(k+1, lower);
    if (car_weights[k] > lower) answer = max(answer, 1 + lisequence(k+1, car_weights[k]));

    lis[make_pair(k, lower)] = answer;
    return answer;
}

int ldsequence(int k, int upper) {
    if (k == n) return 0;
    if (lds.count(make_pair(k, upper))) return lis[make_pair(k,upper)];

    int answer = ldsequence(k+1, upper);
    if (car_weights[k] < upper) answer = max(answer, 1 + ldsequence(k+1, car_weights[k]));

    lds[make_pair(k, upper)] = answer;
    return answer;
}

int main() {
    int test_cases;
    scanf("%d", &test_cases);

    for (int i = 0; i < test_cases; i++) {
        scanf("%d", &n);

        for (int j = 0; j < n; j++) scanf("%d", &car_weights[j]);

        lis.clear();
        lds.clear();

        if (n == 0) printf("0\n");
        else printf("%d\n", 1 + ldsequence(0, car_weights[0]) + lisequence(0, car_weights[0]));
    }
}