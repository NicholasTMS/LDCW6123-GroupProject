#include "features.h"

vector<Transaction> transactions;

string get_current_timestamp() {
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);
    char buf[64];
    // YYYY-MM-DD HH:MM:SS
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", ltm);
    return string(buf);
}

void log_transaction(const string &receiver, double amount, const string &sender) {
    Transaction tx;
    tx.sender = sender;
    tx.receiver = receiver;
    tx.amount = amount;
    tx.timestamp = get_current_timestamp();
    transactions.push_back(tx);
}

void print_transaction_history() {
    if (transactions.empty()) {
        cout << "No transactions yet.\n";
        return;
    }
    cout << "\nTransaction History:\n";
    cout << left
         << setw(15) << "Sender"
         << setw(15) << "Receiver"
         << setw(12) << "Amount"
         << setw(25) << "Timestamp" << "\n";
    cout << string(70, '-') << "\n";

    for (auto &tx : transactions) {
        cout << left
             << setw(15) << tx.sender
             << setw(15) << tx.receiver
             << "RM " << setw(8) << fixed << setprecision(2) << tx.amount
             << setw(25) << tx.timestamp << "\n";
    }
    cout << "\n";
}