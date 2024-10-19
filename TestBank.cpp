#include "TestBank.h"
#include <iostream>

void TestBank::addAccount(const PersonalAccount& account) {
    accounts.push_back(account);
}

void TestBank::printAccounts() const {
    for (const auto& account : accounts) {
        std::cout << account.toString() << std::endl;
    }
}

void TestBank::printAccountTypesCount() const {
    int checkingCount = 0;
    int savingsCount = 0;

    for (const auto& account : accounts) {
        if (account.getAccountType() == "Checking") {
            checkingCount++;
        } else if (account.getAccountType() == "Savings") {
            savingsCount++;
        }
    }

    std::cout << std::endl << "Number of checking accounts: " << checkingCount << std::endl;
    std::cout << std::endl << "Number of savings accounts: " << savingsCount << std::endl;
}

void TestBank::printTotalBalanceForPerson(const std::string& accountHolderName) const {
    double totalBalance = 0.0;

    for (const auto& account : accounts) {
        if (account.getAccountHolderName() == accountHolderName) {
            totalBalance += account.getBalance();
        }
    }

    std::cout << "Total balance for " << accountHolderName << ": " << totalBalance << std::endl;
}