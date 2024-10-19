#include "PersonalAccount.h"

PersonalAccount::PersonalAccount(int accountNumber, std::string bankName, std::string accountType, std::string accountHolderName, double balance)
    : Account(accountNumber, std::move(bankName), std::move(accountType)), accountHolderName(std::move(accountHolderName)), balance(balance) {}

std::string PersonalAccount::getAccountHolderName() const {
    return accountHolderName;
}

double PersonalAccount::getBalance() const {
    return balance;
}

std::string PersonalAccount::toString() const {
    return Account::toString() + "\nAccount holder name: " + accountHolderName + "\nBalance: " + std::to_string(balance);
}