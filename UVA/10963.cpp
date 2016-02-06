#include <iostream>
#include <set>

using namespace std;

int main() {
    int test_cases;
    cin >> test_cases;

    for (int i = 0; i < test_cases; i++) {
        if (i != 0) cout << endl;
        set<int> values;

        int columns;
        cin >> columns;
        for (int j = 0; j < columns; j++) {
            int top, bottom;
            cin >> top >> bottom;
            values.insert(abs(top - bottom));
        }

        if (values.size() == 1) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}