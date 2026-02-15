#include <iostream>
//class BankAccount
class BankAccount {
private:
    std::string accountNumber;
    std::string holderName;
    double balance;
    bool isFrozen;

public:
    // constructor
    BankAccount(std::string accNum, std::string name, double initBal) {
        accountNumber = accNum;
        holderName = name;
        balance = initBal;
        isFrozen = false;
    }

    // functionality
    void deposit(double amount) {
        if(!isFrozen) balance += amount;
    }
    bool withdraw(double amount) {
        if(balance >= amount && !isFrozen) {
            balance -= amount;
            return true;
        }

        return false;
    }
    void display() const {
        std::cout << "=======Account Details=======\n"
                  << "Holder Name: " << holderName
                  << "\nBalance: " << balance << std::endl;
    }

    // Auditor can access all the private members
    friend class Auditor;
};
class Auditor {
public:
    void inspectAccount(const BankAccount& account) {
        std::cout << "=======Account Details=======\n"
                  << "Holder Name: " << account.holderName
                  << "Account Number: " << account.accountNumber
                  << "\nBalance: " << account.balance << std::endl;
    }
    bool detectSuspiciousActivity(const BankAccount& account) {
        if(!(account.balance >  0 && account.balance < 1000000)) return true;
        return false;
    }
    void freezeAccount(BankAccount& account) {
        account.isFrozen = true;
    }
    void unfreezeAccount(BankAccount& account) {
        account.isFrozen = false;
    }
};

// main function
int main() {
    BankAccount acc1("ACC001", "Ali Khan", 50000);
    BankAccount acc2("ACC002", "Sara Ahmed", 1500000);
    acc1.deposit(10000);
    acc1.withdraw(5000);
    acc1.display();
    Auditor auditor;
    std::cout << "\n--- Audit Report---" << std::endl;
    auditor.inspectAccount(acc1);
    if (auditor.detectSuspiciousActivity(acc2)) {
    std::cout << "Suspicious activity detected on ACC002!" << std::endl;
    auditor.freezeAccount(acc2);
    }
    acc2.withdraw(100); // Should fail (frozen)
    auditor.unfreezeAccount(acc2);
    acc2.withdraw(100); // Should succeed


    return 0;
}