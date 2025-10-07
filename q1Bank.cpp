#include <iostream>

using namespace std;

// make globral int for transactions
int totalTransactions = 0;


// make static variable inside transactionCount() to count transactions
int transactionCount(){ // to be called whenever a transaction is made
    static int count = 0;
    count++;
    return count;
}

//  make functions for deposit and withdraw
void deposit(double &balance, double amount){
    if(amount < 0){
        cout << "Error: Cannot deposit a negative amount. Please withdraw.";
        return;
    }
    balance += amount; // add to balance
    transactionCount(); // call static increment
    totalTransactions++; // increment global

    // print update message
    cout << "Deposited $" << amount << ". New balance: " << balance; 
}

void withdraw(double &balance, double amount){
    if(amount > balance){
        cout << "You just crashed the whole bank!";
        exit(0);
    }
    balance -= amount; // subtract from balance
    transactionCount(); // call static increment
    totalTransactions++; // increment global
    // print update message
    cout << "Withdrew $" << amount << ". New balance: " << balance; 
}

// total balance 
double getTotalBalance(const double accounts[], int size){
    double total = 0;
    for(int i = 0; i < size; i++){
        total += accounts[i]; // go through each account to get balance
    }
    return total; // return total ammount after going through each
}
// make message function 
void displayMessage(string msg){
    cout << msg;
}



int main(){
    // stores balances for 5 accounts in an array
    double bank[5] = {0,0,0,0,0}; // initalize 5 accounts starting at $0 

    int choice,amount,account;
    while(true){
        cout << "\nWhat can we do for you today?\n";
        cout << "1)Deposit\n2)Withdraw\n3)Print total\n4)Exit\n";

        cin >> choice;
        if(choice == 1){
            cout << "Please select which account:\n";
            cin >> account;
            cout << "How much will you deposit?\n";
            cin >> amount;
            
            if((account + 1) < 5){ // do account + 1 since arrays start at 0
                deposit(bank[account - 1], amount);// function call to deposit
            }    
            cout << "Invalid account. Entering main menu....\n";
        }
        else if(choice == 2){
            cout << "Please select which account:\n";
            cin >> account;
            cout << "How much will you withdraw?\n";
            cin >> amount;
            // do account + 1 since array starts at 0
            withdraw(bank[account - 1], amount); // function call to withdraw
        }
        else if(choice == 3){
            cout << "Please enter your badge number: "; 
            cin;
            cout << "\nConfirmed.\nTotal balance across all accounts: ";
            cout << getTotalBalance(bank,5); //function call to get total balance
        }
        else if(choice == 4){
            // show comparison of static and global variable
            cout << "(transactionsCount called" << transactionCount() << " times\n";
            cout << "(totalTransactions = " << totalTransactions << ")\n";
            displayMessage("Logging off.");
            break; // break from loop
        }
        else{
            cout <<"Error:Enter valid choice.\n";
            continue;
        }
    }

    return 0;
}