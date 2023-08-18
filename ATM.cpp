#include <iostream>
#include <vector>

class Account {
private:
    int accountNumber;
    std::string accountHolder;
    double balance;

public:

    Account(int number, std::string holder, double initialBalance) {
        accountNumber = number;
        accountHolder = holder;
        balance = initialBalance;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited $" << amount << " into account " << accountNumber << std::endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            std::cout << "Withdrawn $" << amount << " from account " << accountNumber << std::endl;
        } else {
            std::cout << "Insufficient balance or invalid amount for account " << accountNumber << std::endl;
        }
    }

    void display() const {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder: " << accountHolder << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }
};

int main() {
    std::vector<Account> accounts;
    int accountNumberCounter = 1000;

    while (true) {
        std::cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Display Account Details\n5. Exit" << std::endl;
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string holder;
                double initialBalance;
                std::cout << "Enter account holder's name: ";
                std::cin >> holder;
                std::cout << "Enter initial balance: ";
                std::cin >> initialBalance;
                accounts.emplace_back(accountNumberCounter++, holder, initialBalance);
                std::cout << "Account created with number " << accountNumberCounter - 1 << std::endl;
                break;
            }
            case 2: {
                int accountNumber;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter deposit amount: ";
                std::cin >> amount;
                for (Account& acc : accounts) {
                    if (acc.getAccountNumber() == accountNumber) {
                        acc.deposit(amount);
                        break;
                    }
                }
                break;
            }
            case 3: {
                int accountNumber;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                for (Account& acc : accounts) {
                    if (acc.getAccountNumber() == accountNumber) {
                        acc.withdraw(amount);
                        break;
                    }
                }
                break;
            }
            case 4: {
                int accountNumber;
                std::cout << "Enter account number: ";
                std::cin >> accountNumber;
                for (const Account& acc : accounts) {
                    if (acc.getAccountNumber() == accountNumber) {
                        acc.display();
                        break;
                    }
                }
                break;
            }
            case 5:
                std::cout << "Exiting program." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please choose a valid option." << std::endl;
        }
    }

    return 0;
}

