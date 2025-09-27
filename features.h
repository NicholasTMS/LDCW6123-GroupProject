#ifndef features_h
#define features_h

#include <iostream>
#include <iomanip>  
#include <vector>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

void menu();

struct Transaction {
    string sender;      
    string receiver;    
    double amount;
    string timestamp;
};
void log_transaction(const string &receiver, double amount, const string &sender = "Me");
void print_transaction_history();

void topup(double &balance);

void qr_payment(double &balance);

void toll_payment(double &balance);

#endif  
