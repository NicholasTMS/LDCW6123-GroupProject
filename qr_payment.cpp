#include "features.h"

void qr_payment(double &balance) {
    string merchant;
    double amount;
    cout << "Enter merchant name: ";
    cin.ignore();
    getline(cin, merchant);
    do {
        cout << "Enter amount to pay (RM): ";
        cin >> amount;
        amount = round(amount * 100.0) / 100.0;
        if (amount <= 0) {
            cout << "Invalid amount. Must be greater than 0.\n";
        }
    } while (amount <= 0);
    if (amount > balance) {
        cout << "Insufficient balance!\n";
    } else {
        balance -= amount;
        log_transaction(merchant, amount);
        cout << "Paid RM " << fixed << setprecision(2) << amount << " to " << merchant << ".\n";
        cout << "New balance: RM " << fixed << setprecision(2) << balance << "\n";
    }
}