#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>

class Account {
private:
    int accountNumber;
    std::string bankName;
    std::string accountType;

public:
    Account(int accountNumber, std::string bankName, std::string accountType);
    virtual ~Account();
    [[nodiscard]] int getAccountNumber() const;
    [[nodiscard]] std::string getBankName() const;
    [[nodiscard]] std::string getAccountType() const;
    [[nodiscard]] virtual std::string toString() const;
};

#endif // ACCOUNT_H