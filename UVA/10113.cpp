#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long loan_duration, deprecation_number;
    long double down_payment, loan_amount, deprecation_number;
    cin >> loan_duration >> down_payment >> loan_amount >> deprecation_number;

    vector<long long> deprecation_percentages(loan_duration, 1);

    long long month, percent_deprecation;
    for (long long i = 0; i < deprecation_number; i++) {
        cin >> month, percent_deprecation;
        cout << month << ' ' << percent_deprecation << endl;
        deprecation_percentages[month] = percent_deprecation;
    }

    for (long long i = 0; i < deprecation_percentages.size(); i++) {
        cout << deprecation_percentages[i] << endl;
    }
}