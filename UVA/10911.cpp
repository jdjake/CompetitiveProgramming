/**********************************************************************
 * 10911 - Forming Quiz Teams                                         *
 *                                                                    *
 * This is a standard DP problem. We notice that the matchings of     *
 * people form maximum submatchings, which allow us to recurse onto   *
 * the solution. The algorithm below runs in time                     *
 * equivalent to the recurrence relation                              *
 *                                                                    *
 * f(n) = (n-1)O(f(n-2))                                              *
 * f(0) = O(1)                                                        *
 *                                                                    *
 * We can solve this by determining that f(n) = 1*3*5*...*(n-1)       *
 * Which is at least n!/2(n/2)!, which is non-polynomial. However,    *
 * the number of points is so small that this is possible.            *
 **********************************************************************/

#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <cfloat>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

long double find_best_distance(const vector<tuple<int, int>>& distances,
                               const bitset<16>& used,
                               unordered_map<bitset<16>, long double>& memoize) {
    if (used.count() == distances.size()) return 0;
    if (memoize.count(used) == 1) return memoize.at(used);

    // Find the first unused member of the distances vector.
    int one_value = 0;
    while (used[one_value] == 1) one_value++;

    int one_value_x = get<0>(distances.at(one_value));
    int one_value_y = get<1>(distances.at(one_value));

    // For each other unused member of the distances vector,
    // pair the member with the first unmatched vector, then
    // find the minimum perfect submatching with the pair
    // removed. The total minimum matching will be a pair
    // with a perfect minimum submatching.
    long double minimum = LDBL_MAX;
    for (int i = one_value + 1; i < distances.size(); i++) {
        if (used[i] == 1) continue;

        bitset<16> new_used = used;
        new_used[one_value] = new_used[i] = 1;

        int i_x = get<0>(distances.at(i));
        int i_y = get<1>(distances.at(i));

        long double matching_cost = sqrt(pow((i_x - one_value_x),2)
                                  + pow((i_y - one_value_y),2));

        long double output = matching_cost
                           + find_best_distance(distances, new_used, memoize);

        minimum = min(minimum, output);
    }

    memoize[used] = minimum;
    return minimum;
}

int main() {
    int case_number = 1;
    while (cin) {
        int student_number;
        cin >> student_number;

        if (student_number == 0) return 0;

        vector<tuple<int, int>> coordinates;

        for (int i = 0; i < 2*student_number; i++) {
            string name;
            int x, y;

            cin >> name >> x >> y;

            coordinates.push_back(make_tuple(x,y));
        }

        bitset<16> used;
        unordered_map<bitset<16>, long double> memoize;

        long double best_distance = find_best_distance(coordinates, used,
                                                       memoize);

        cout << "Case " << case_number << ": " << fixed << setprecision(2)
             << best_distance << endl;

        case_number++;
    }

    cout << "Error: Output Not Ended Properly" << endl;
}