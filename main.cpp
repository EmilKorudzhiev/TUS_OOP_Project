#include <iostream>
#include "TestBank.h"

int main() {
    TestBank bank;

    for (int i = 0; i < 5; ++i) {
        std::cout << std::endl << "Enter account: " << i+1 << std::endl;

        int accountNumber;
        std::string bankName, accountType, accountHolderName;
        double balance;

        std::cout << "Enter account number: ";
        std::cin >> accountNumber;
        std::cin.ignore();

        std::cout << "Enter bank name: ";
        std::getline(std::cin, bankName);

        std::cout << "Enter account type (Checking/Savings): ";
        std::getline(std::cin, accountType);

        std::cout << "Enter account holder name: ";
        std::getline(std::cin, accountHolderName);

        std::cout << "Enter balance: ";
        std::cin >> balance;

        PersonalAccount account(accountNumber, bankName, accountType, accountHolderName, balance);
        bank.addAccount(account);
    }

    bank.printAccounts();
    bank.printAccountTypesCount();

    std::string accountHolderName;
    std::cout << "Enter account holder name to get total balance: ";
    std::cin.ignore();
    std::getline(std::cin, accountHolderName);

    bank.printTotalBalanceForPerson(accountHolderName);

    return 0;
}

