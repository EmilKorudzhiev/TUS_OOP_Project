#include <iostream>
#include <stdexcept>
#include <limits>
#include <unistd.h>

#include "TestBank.h"

int main() {
    TestBank bank;
    for (int i = 0; i < 5; ++i) {
        try {
            std::cout << std::endl << "Enter account: " << i + 1 << std::endl;

            int accountNumber;
            std::string bankName, accountType, accountHolderName;
            double balance;

            std::cout << "Enter account number: ";
            if (!(std::cin >> accountNumber)) {
                throw std::invalid_argument("Invalid account number format.");
            }

            std::cout << "Enter bank name: ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::getline(std::cin, bankName);

            std::cout << "Enter account type (Checking/Savings): ";
            std::getline(std::cin, accountType);
            if (accountType != "Checking" && accountType != "Savings") {
                throw std::invalid_argument("Invalid account type. Must be 'Checking' or 'Savings'.");
            }

            std::cout << "Enter account holder name: ";
            std::getline(std::cin, accountHolderName);

            std::cout << "Enter balance: ";
            if (!(std::cin >> balance)) {
                throw std::invalid_argument("Invalid balance format.");
            }
            PersonalAccount account(accountNumber, bankName, accountType, accountHolderName, balance);
            bank.addAccount(account);

        } catch (const std::exception& e) {
            std::cerr << "Error adding account " << i + 1 << ": " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            --i;
            sleep(1);
        }
    }

    try {
        bank.printAccounts();
    } catch (const std::exception& e) {
        std::cerr << "Error printing accounts: " << e.what() << std::endl;
    }

    try {
        bank.printAccountTypesCount();
    } catch (const std::exception& e) {
        std::cerr << "Error printing account types count: " << e.what() << std::endl;
    }

    try {
        std::string accountHolderName;
        std::cout << "Enter account holder name to get total balance: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, accountHolderName);

        bank.printTotalBalanceForPerson(accountHolderName);
    } catch (const std::exception& e) {
        std::cerr << "Error getting total balance: " << e.what() << std::endl;
    }

    return 0;
}