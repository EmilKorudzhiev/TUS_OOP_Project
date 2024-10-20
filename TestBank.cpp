#include "TestBank.h"
#include <iostream>
#include <stdexcept>
#include <string>

void TestBank::addAccount(const PersonalAccount& account) {
    for (const auto& existingAccount : accounts) {
        if (existingAccount.getAccountHolderName() == account.getAccountHolderName() &&
            existingAccount.getAccountType() == account.getAccountType()) {
            throw std::runtime_error("Account already exists for this account holder.");
        }
    }

    accounts.push_back(account);
}

void TestBank::printAccounts() const {
    if (accounts.empty()) {
        throw std::runtime_error("No accounts available to display.");
    }
    for (const auto& account : accounts) {
        std::cout << std::endl << account.toString() << std::endl;
    }
}

void TestBank::printAccountTypesCount() const {
    if (accounts.empty()) {
        throw std::runtime_error("No accounts available to count.");
    }
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
    std::cout << "Number of savings accounts: " << savingsCount << std::endl;
}

void TestBank::printTotalBalanceForPerson(const std::string& accountHolderName) const {
    double totalBalance = 0.0;
    bool accountFound = false;
    for (const auto& account : accounts) {
        if (account.getAccountHolderName() == accountHolderName) {
            totalBalance += account.getBalance();
            accountFound = true;
        }
    }
    if (!accountFound) {
        throw std::runtime_error("No account found for the account holder: " + accountHolderName);
    }
    std::cout << "Total balance for " << accountHolderName << ": " << totalBalance << std::endl;
}
