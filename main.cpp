#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) : type(t), amount(a) {}
};

class Account {
private:
    int accountNumber;
    double balance;
    vector<Transaction> history;

public:
    Account(int id) : accountNumber(id), balance(0.0) {}

    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
        cout << "Deposited $" << amount << " successfully." << endl;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            cout << "Error: Insufficient funds!" << endl;
            return false;
        }
        balance -= amount;
        history.push_back(Transaction("Withdrawal", amount));
        return true;
    }

    void displayInfo() {
        cout << "\nAccount ID: " << accountNumber << " | Balance: $" << balance << endl;
        cout << "Recent Transactions:" << endl;
        for (auto &t : history) {
            cout << "- " << t.type << ": $" << t.amount << endl;
        }
    }

    int getID() { return accountNumber; }
    double getBalance() { return balance; }
};

class Customer {
public:
    string name;
    Account* account;

    Customer(string n, int id) : name(n) {
        account = new Account(id);
    }
};

void transferFunds(Account &from, Account &to, double amount) {
    if (from.withdraw(amount)) {
        to.deposit(amount);
        cout << "Transfer of $" << amount << " completed." << endl;
    }
}

int main() {
    Customer c1("Alice", 101);
    Customer c2("Bob", 102);

    c1.account->deposit(500);
    c1.account->withdraw(100);

    transferFunds(*(c1.account), *(c2.account), 150);

    c1.account->displayInfo();
    c2.account->displayInfo();

    return 0;
}
