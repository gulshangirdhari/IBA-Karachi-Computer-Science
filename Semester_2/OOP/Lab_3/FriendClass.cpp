#include <iostream>
#include <string>
class BankAccount {
    private: 
        double balance;
        std::string accountNumber;
    public:
        BankAccount(std::string acc, double bal) : accountNumber(acc), balance(bal) {}

    // Auditor can access all private members
    friend class Auditor;
};

class Auditor {
    public: 
        void checkAccount(const BankAccount& account) {
            std::cout << "Account: " << account.accountNumber 
                      << "\nBalance: " <<  account.balance << std::endl;
        }
};

int main() {

    BankAccount b1("44032487876", 135);
    Auditor a1;
        a1.checkAccount(b1);

    return 0;
}