#ifndef TESTBANK_H
#define TESTBANK_H

#include "PersonalAccount.h"
#include <vector>
#include <string>

class TestBank {
private:
    std::vector<PersonalAccount> accounts;

public:
    void addAccount(const PersonalAccount& account);
    void printAccounts() const;
    void printAccountTypesCount() const;
    void printTotalBalanceForPerson(const std::string& accountHolderName) const;
};

#endif // TESTBANK_H