#include <iostream>
#include <vector>

#define ARRAY 999
#define BIG 999999
#define EPS 0.00001

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

using namespace std;
vector< vector<int> > elevations(999, vector<int>(999));

int m,n;

long double volume(float level) {
    float sum = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << level << " " << elevations[i][j] << " " << level - elevations[i][j] << endl;
            sum += MAX(0, level - elevations[i][j]);
        }
    }

    return sum;
}

int main() {
    int test_number = 0;

    while(test_number++, cin >> m >> n, m != 0 || n != 0) {
        cout << "Region " << test_number << endl;
        vector< vector<int> > elevations(m, vector<int>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int elevation;
                cin >> elevation;
                elevations[i][j] = elevation;
            }
        }

        int water_amount;
        cin >> water_amount;

        long double low = -BIG;
        long double big = BIG;

        cout << volume(10) << endl;

        while (big - low > EPS) {
            cout << low << " " << big << endl;
            long double middle = (low + big)/2;
            long double estimate = volume(middle);
            cout << estimate << " " << water_amount << endl;

            if (estimate > water_amount) big = middle;
            else low = middle;
        }

        long double answer = (big + low)/2;
        cout << "Water level is " << answer << " meters.";
    }
}