/***************************************************************************
 *   10114 - Loansome Car Buyer                                            *
 *                                                                         *
 *   This is an easy simulation problem with some nasty subtle bugs.       *
 *   Watch out for:                                                        *
 *       - How Downpayments work (I need to learn adult things sometime)   *
 *           Divide the loan the length of the loan payment to get         *
 *           monthly payment. Don't subtract the down payment each         *
 *           month.                                                        *
 *       - You can get the answer at the 0 month mark                      *
 *           In this case. Make sure you output `0 months' instead of      *
 *           `0 month'. The problem clearly states that you should only    *
 *           use the singular in the case of one month.                    *
 ***************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    int month_duration, num_records;
    long double down_payment, loan_amount;

    while (!cin.eof()) {
        cin >> month_duration >> down_payment >> loan_amount >> num_records;

        if (month_duration < 0) break;

        vector<long double> records (month_duration+1);

        for (int i = 0; i < num_records; i++) {
            int month_number;
            cin >> month_number;
            cin >> records[month_number];
        }

        long double last_value = 0;
        for (auto& i: records) {
            if (i == 0) i = last_value;
            else last_value = i;
        }

        long double down_payments = loan_amount;
        long double monthly_payment = loan_amount/month_duration;
        loan_amount = (loan_amount + down_payment)*(1 - records.at(0));
        if (down_payments < loan_amount) {
            cout << "0 months" << endl;
            continue;
        }
        for (int i = 1; i < records.size(); i++) {
            down_payments -= monthly_payment;
            loan_amount *= 1 - records.at(i);
//            cout << i << ' ' << down_payments << ' ' << loan_amount << endl;

            if (down_payments < loan_amount) {
                if (i != 1) cout << i << " months" << endl;
                else cout << i << " month" << endl;
                break;
            }
        }
    }
}