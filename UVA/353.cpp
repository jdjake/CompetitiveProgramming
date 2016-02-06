#include <iostream>
#include <string>
#include <set>

using namespace std;

bool is_palindrome(string x) {
    for (int i = 0; i < x.size(); i++) {
        if (x.at(i) != x.at(x.size() - i - 1)) return false;
    }

    return true;
}

int main() {
    string input;
    while (!cin.eof()) {
        getline(cin, input);
        if (input == "") continue;

        set<string> palindromes;

        for (int i = 0; i < input.size(); i++) {
            for (int j = i; j < input.size(); j++) {
                string sub = input.substr(i,j - i + 1);
                if (is_palindrome(sub)) palindromes.insert(sub);
            }
        }

        cout << "The string '"     << input           << "' contains "
             << palindromes.size() << " palindromes." << endl;
    }
}