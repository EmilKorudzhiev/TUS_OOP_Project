#ifndef PERSONALACCOUNT_H
#define PERSONALACCOUNT_H

#include "Account.h"
#include <string>

class PersonalAccount : public Account {
private:
    std::string accountHolderName;
    double balance;

public:
    PersonalAccount(int accountNumber, std::string bankName, std::string accountType, std::string accountHolderName, double balance);
    [[nodiscard]] std::string getAccountHolderName() const;
    [[nodiscard]] double getBalance() const;
    [[nodiscard]] std::string toString() const override;
};

#endif // PERSONALACCOUNT_H