#include "Account.h"

Account::Account(const int accountNumber, std::string bankName, std::string accountType)
    : accountNumber(accountNumber), bankName(std::move(bankName)), accountType(std::move(accountType)) {}

Account::~Account() = default;

int Account::getAccountNumber() const {
    return accountNumber;
}

std::string Account::getBankName() const {
    return bankName;
}

std::string Account::getAccountType() const {
    return accountType;
}

std::string Account::toString() const {
    return "Account number: " + std::to_string(accountNumber)
    + "\nBank name: " + bankName
    + "\nAccount type: " + accountType;
}