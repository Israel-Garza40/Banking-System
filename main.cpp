//Israel Garza
//Banking Systems Project
//Due Date: 2-16-25
//ITSE 1302-201

#include <iostream>
#include <cassert>

using namespace std;

int main() {
    double balance = 0.0;  // Initial balance
    int choice;
    double amount;
    
    while (true) {
        // Display menu
        cout << "\n===== Banking System =====" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Exit" << endl;
        cout << "Select an option: ";
        cin >> choice;

        // Validate input
        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear(); // Clear error flag
            cin.ignore(1000, '\n'); // Discard invalid input
            cout << "Invalid option! Please choose a valid menu option.\n";
            continue;
        }

        switch (choice) {
            case 1:
                // Show balance
                cout << "Your current balance is: $" << balance << endl;
                break;

            case 2:
                // Deposit money
                cout << "Enter deposit amount: ";
                cin >> amount;

                if (amount > 0) {
                    balance += amount;
                    cout << "Deposit successful! New balance: $" << balance << endl;
                } else {
                    cout << "Invalid amount! Deposit must be positive.\n";
                }
                break;

            case 3:
                // Withdraw money
                cout << "Enter withdrawal amount: ";
                cin >> amount;

                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    assert(balance >= 0); // Ensuring balance never goes negative
                    cout << "Withdrawal successful! New balance: $" << balance << endl;
                } else if (amount <= 0) {
                    cout << "Invalid withdrawal amount! Must be greater than 0.\n";
                } else {
                    cout << "Insufficient funds! Withdraw failed.\n";
                }
                break;

            case 4:
                // Exit the program
                cout << "Thank you for using our banking system. Goodbye!\n";
                return 0;

            default:
                // Should never reach here due to input validation
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}