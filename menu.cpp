#include "features.h"

void menu(){
    double balance;
    bool running = true;

    cout << "=====================================\n";
    cout << "   Touch'n'Go eWallet Simulator G13 \n";
    cout << "=====================================\n\n";

    do {
        cout << "Enter balance (RM): ";
        cin >> balance;
        if (balance < 0){
            cout << "Please enter an amount greater than 0" << endl;
        }
        else{
            balance = round(balance * 100.0) / 100.0;
        }
    } while (balance < 0);


    do {
        cout << "\nMenu:\n";
        cout << " 1) Check balance\n";
        cout << " 2) Top up (reload)\n";
        cout << " 3) Pay toll (RFID)\n";
        cout << " 4) Pay merchant (QR)\n";
        cout << " 5) View transactions\n";
        cout << " 6) Exit\n";
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Current balance: RM " << fixed << setprecision(2)
                     << balance << "\n";
                break;

            case 2: {
                topup(balance);
                cout << "New balance: RM " << fixed << setprecision(2) << balance << "\n";
                break;
            }

            case 3: {
                toll_payment(balance);
                break;
            }

            case 4: {
                qr_payment(balance);
                break;
            }

            case 5:
                print_transaction_history();
                break;
                
            case 6: 
                cout << "We hope you enjoyed our app. Goodbye!\n";
                running = false;
                break;
            default:
                cout << "Invalid input. Try again with a number from 1 to 6\n";
        } 
    } while (running);
}
