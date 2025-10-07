#include <iostream>
#include <cstdlib>  
using namespace std;

int totalTransactions = 0; 

// Function prototypes
void deposit(double &balance, double amount);
void withdraw(double &balance, double amount);
double getTotalBalance(const double accounts[], int size);
int transactionCount();
void displayMessage(string msg = "Transaction complete");

int main() {
    double accounts[5] = {0.0};
    int choice, acc;
    double amount;

    while (true) {
        cout << "\n1. Deposit\n2. Withdraw\n3. Show total balance\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account (0-4) and amount: ";
                cin >> acc >> amount;
                deposit(accounts[acc], amount);
                displayMessage();
                break;

            case 2:
                cout << "Enter account (0-4) and amount: ";
                cin >> acc >> amount;
                withdraw(accounts[acc], amount);
                displayMessage();
                break;

            case 3:
                cout << "Total balance across all accounts = " 
                     << getTotalBalance(accounts, 5) << endl;
                cout << "(transactionCount called " << transactionCount() 
                     << " times)" << endl;
                cout << "(totalTransactions = " << totalTransactions << ")" << endl;
                break;

            case 4:
                exit(0);
        }
    }
    return 0;
}

void deposit(double &balance, double amount) {
    balance += amount;
    totalTransactions++;
    cout << "Deposited $" << amount << ". New balance = " << balance << endl;
}

void withdraw(double &balance, double amount) {
    if (amount > balance) {
        cout << "Insufficient balance! Exiting...\n";
        exit(0);
    }
    balance -= amount;
    totalTransactions++;
    cout << "Withdrew $" << amount << ". New balance = " << balance << endl;
}

double getTotalBalance(const double accounts[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++)
        total += accounts[i];
    return total;
}

int transactionCount() {
    static int count = 0;
    count = totalTransactions;
    return count;
}

void displayMessage(string msg) {
    cout << msg << endl;
}
