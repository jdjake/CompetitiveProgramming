#include <iostream>
#include <string>

using namespace std;

int main(void) {
    // Program doesn't even compute anything
    // read line in, print line out, read line in...
    string input;
    while (getline(cin, input)) {
        cout << input << '\n';
    }
}