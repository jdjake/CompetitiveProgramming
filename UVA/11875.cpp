#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int test_cases;
    scanf("%d", &test_cases);

    for (int i = 1; i <= test_cases; i++) {
        int team_members;
        scanf("%d", &team_members);

        vector<int> members;

        for (int j = 0; j < team_members; j++) {
            int team_member;
            scanf("%d", &team_member);

            members.push_back(team_member);
        }

        sort(members.begin(), members.end());
        printf("Case %d: %d\n", i, members[team_members/2]);
    }
}