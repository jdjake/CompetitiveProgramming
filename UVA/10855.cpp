#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<char> > read_square(long n) {
    vector< vector<char> > chars(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char y;
            cin >> y;
            chars[i].push_back(y);
        }
    }

    return chars;
}

vector< vector<char> > rotate_square(vector< vector<char> > square) {
    vector< vector<char> > new_square = square;

    for (int i = 0; i < new_square.size(); i++) {
        for (int j = 0; j < new_square.size(); j++) {
            new_square[j][i] = square[i][j];
        }
    }

    for (int i = 0; i < new_square.size(); i++)
        reverse(new_square[i].begin(), new_square[i].end());

    return new_square;
}

bool is_inside(const vector< vector<char> > &big,
               const vector< vector<char> > &small,
               long long i, long long j) {
    for (long long k = 0; k < small.size(); k++) {
        for (long long l = 0; l < small.size(); l++) {
            if (big[i + k][j + l] != small[k][l]) return false;
        }
    }

    return true;
}

long find_inside(const vector< vector<char> >& big,
                 const vector< vector<char> >& small) {
    long count = 0;

    for (long long i = 0; i < big.size() - small.size(); i++) {
        for (long long j = 0; j < big.size() - small.size(); j++) {
            if (is_inside(big, small, i, j)) count++;
        }
    }

    return count;
}

int main() {
    while(true) {
        long long n, N;
        cin >> N >> n;

        if (n == 0 && N == 0) return 0;

        vector< vector<char> > n_square       {read_square(n)};
        vector< vector<char> > rotated_once   {rotate_square(n_square)};
        vector< vector<char> > rotated_twice  {rotate_square(rotated_once)};
        vector< vector<char> > rotated_thrice {rotate_square(rotated_twice)};

/*        for (int i = 0; i < n_square.size(); i++) {
            for (int j = 0; j < n_square.size(); j++) {
                cout << n_square[i][j] << " ";
            }

            cout << endl;
        }
        for (int i = 0; i < n_square.size(); i++) {
            for (int j = 0; j < n_square.size(); j++) {
                cout << rotated_once[i][j] << " ";
            }

            cout << endl;
        }*/

        vector< vector<char> > N_square {read_square(N)};

        long first  {find_inside(N_square, n_square)};
        long second {find_inside(N_square, rotated_once)};
        long third  {find_inside(N_square, rotated_twice)};
        long fourth {find_inside(N_square, rotated_thrice)};

        cout << first << " " << second << " " << third << " " << fourth << endl;
    }
}