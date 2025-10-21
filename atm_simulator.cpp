#include <iostream>
#include <iomanip>  // for fixed and setprecision
using namespace std;

// --- Function Prototypes ---
void displayMenu();
double checkBalance(double balance);
void deposit(double &balance, double amount);
void withdraw(double &balance, double amount);

// --- Main Function ---
int main() {
    double balance = 0.0;
    int choice;
    double amount;
    bool running = true;

    cout << "============================\n";
    cout << "   Welcome to the ATM!\n";
    cout << "============================\n";

    while (running) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << fixed << setprecision(2);
                cout << "Your current balance is: $" << checkBalance(balance) << endl;
                break;

            case 2:
                cout << "Enter the amount to deposit: $";
                cin >> amount;
                deposit(balance, amount);
                break;

            case 3:
                cout << "Enter the amount to withdraw: $";
                cin >> amount;
                withdraw(balance, amount);
                break;

            case 4:
                cout << "Thank you for using our ATM. Goodbye!" << endl;
                running = false;
                break;

            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }

        cout << endl; // Add a blank line between operations
    }

    return 0;
}

// --- Function Definitions ---

void displayMenu() {
    cout << "----------------------------\n";
    cout << "1. Check Balance\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Exit\n";
    cout << "----------------------------\n";
}

double checkBalance(double balance) {
    return balance;
}

void deposit(double &balance, double amount) {
    if (amount <= 0) {
        cout << "Deposit amount must be greater than zero.\n";
        return;
    }
    balance += amount;
    cout << fixed << setprecision(2);
    cout << "Deposit successful. New balance: $" << balance << endl;
}

void withdraw(double &balance, double amount) {
    if (amount <= 0) {
        cout << "Withdrawal amount must be greater than zero.\n";
        return;
    }
    if (amount > balance) {
        cout << "Insufficient funds. Withdrawal canceled.\n";
        return;
    }
    balance -= amount;
    cout << fixed << setprecision(2);
    cout << "Withdrawal successful. New balance: $" << balance << endl;
}