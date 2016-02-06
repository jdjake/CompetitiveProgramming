#include <iostream>

using namespace std;

int main() {
    while (true) {
        long c;
        cin >> c;

        if (c == 0) break;

        long sum = 0;
        while (c != 0) {
            sum += c % 10;
            c /= 10;
        }

        cout << sum << endl;
    }
}