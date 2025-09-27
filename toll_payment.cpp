#include "features.h"


void toll_payment(double &balance) {
    
    vector<string> highways = {"PLUS", "LDP", "NKVE", "KESAS", "SPRINT"};
    cout << "Available highways:\n";
    for (size_t i = 0; i < highways.size(); ++i) {
        cout << " " << (i + 1) << ") " << highways[i] << "\n";
    }

    int choice;
    do {
        cout << "Choose a highway (1-" << highways.size() << "): ";
        cin >> choice;
        if (choice < 1 || choice > highways.size()) {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice < 1 || choice > highways.size());

    string selected_highway = highways[choice - 1];
    double toll_amount = 0.0;
    if (selected_highway == "PLUS") toll_amount = 5.00;
    else if (selected_highway == "LDP") toll_amount = 3.50;
    else if (selected_highway == "NKVE") toll_amount = 4.00;
    else if (selected_highway == "KESAS") toll_amount = 2.50;
    else if (selected_highway == "SPRINT") toll_amount = 3.00;

    cout << "Toll for " << selected_highway << ": RM " << fixed << setprecision(2) << toll_amount << "\n";

    char confirm;
    cout << "Confirm payment of RM " << fixed << setprecision(2) << toll_amount << " for " << selected_highway << "? (Y/N): ";
    cin >> confirm;
    if (confirm != 'Y' && confirm != 'y') {
        cout << "Payment cancelled.\n";
        return;
    }

    if (toll_amount > balance) {
        cout << "Insufficient balance to pay the toll!\n";
    } else {
        balance -= toll_amount;
        log_transaction("Toll - " + selected_highway, toll_amount);
        cout << "Toll paid successfully. New balance: RM " << fixed << setprecision(2) << balance << "\n";
    }
}
