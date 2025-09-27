#include "features.h"

void topup(double &balance) {
    double amount;
    do {
        cout << "Enter top-up amount (RM): ";
        cin >> amount;
        if (amount <= 0) {
            cout << "Invalid amount. Please try again." << endl;
        } else {
            amount = round(amount * 100.0) / 100.0; // Round to 2 decimal places
            balance += amount;
            cout << "Top-up successful! New balance: RM " << fixed << setprecision(2) << balance << "\n";
            log_transaction("Me", amount);
        }
    } while (amount <= 0);
}
