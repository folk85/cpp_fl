/*
2. Bank Account System
   Create a class hierarchy to represent a Bank Account system:
   - Base class Account should have:
     - Data members for account number, balance, and owner's name.
     - A virtual function void deposit(double amount) to increase balance.
     - A virtual function void withdraw(double amount) to decrease balance.
   - Derived class SavingsAccount should override withdraw() to restrict withdrawals if the balance falls below a minimum threshold.
   - Derived class CheckingAccount should override withdraw() to allow withdrawals but charge a fee if the balance falls below a certain limit.
   - Use polymorphism to manage different account types in a banking system.
   - Implement a system where transactions are logged, and each account tracks its own transaction history (e.g., store a list of transaction descriptions).
*/

#include <iostream>     // to use std::cout
#include <vector>       // add std sdt::vector
#include <string>       // to use std::string

class BankAccount {
  protected:

  unsigned long int accountNumber;  // Account number
  double balance;             // Account balance
  std::string ownerName;      // Owner's name
  std::vector<std::string> transactionHistory;  // Transaction history by account
  
  public:

  // Constructor
  BankAccount(
      const unsigned long int accountNumber, 
      const double balance, 
      const std::string& ownerName
    ) :     
      accountNumber(accountNumber), balance(balance), ownerName(ownerName) 
  {
    std::cout << "BankAccount constructor called" << std::endl;
  }

  // deposit function
  virtual void deposit(const double amount) {
    this->balance += amount;
    this->transactionHistory.push_back("Deposit: " + std::to_string(amount) + " Balance: " + std::to_string(this->balance));
  }

  // withdraw function
  virtual void withdraw(const double amount) {
    this->balance -= amount;
    this->transactionHistory.push_back("Withdraw: " + std::to_string(amount) + " Balance: " + std::to_string(this->balance));
  }
  //Destructor
  virtual ~BankAccount() {
    std::cout << "BankAccount destructor called" << std::endl;
  }

  // Print account's transaction information
  void printTransactionHistory() const {
    std::cout << "Transaction history for account " << this->accountNumber << ":" << std::endl;
    for (const std::string& transaction : this->transactionHistory) {
      std::cout << transaction << std::endl;
    }
  }
};

// Define Derived type SavingsAccount
class SavingAccount: public BankAccount {
  protected:
  double minThreshold;  // Minimum threshold for withdrawal

  public:

  // Constructor
  SavingAccount(
      const unsigned long int accountNumber, 
      const double balance, 
      const std::string& ownerName,
      const double minThreshold
    ) : BankAccount(accountNumber, balance, ownerName), minThreshold(minThreshold) 
  {
    std::cout << "SavingAccount constructor called" << std::endl;
  }

  // withdraw function
  void withdraw(const double amount) override {
    double localAmount = 0.0;
    if (this->balance - amount >= this->minThreshold) {
      this->balance -= amount;
      localAmount = amount;
    }
    this->transactionHistory.push_back("Withdraw: " + std::to_string(localAmount) + " Balance: " + std::to_string(this->balance));
  }

  //Destructor
  virtual ~SavingAccount() {
    std::cout << "SavingAccount destructor called" << std::endl;
  }
};

// Define Derived type CheckingAccount
class CheckingAccount: public SavingAccount {
  double fee;  // Fee for withdrawal
  public:

  // Constructor
  CheckingAccount(
      const unsigned long int accountNumber, 
      const double balance, 
      const std::string& ownerName,
      const double fee,
      const double limit
  ) : SavingAccount(accountNumber, balance, ownerName, limit), fee(fee) 
  {
    std::cout << "CheckingAccount constructor called" << std::endl;
  }

  // withdraw function
  void withdraw(const double amount) override {
    double localAmount = amount;
    if (this->balance - amount >= this->minThreshold) {
      this->balance -= amount;
    } else {
      this->balance -= amount + this->fee;
      localAmount += this->fee;
    }
    this->transactionHistory.push_back("Withdraw: " + std::to_string(localAmount) + " Balance: " + std::to_string(this->balance));
  }

  //Destructor
  ~CheckingAccount() {
    std::cout << "CheckingAccount destructor called" << std::endl;
  }
};



int main() {
  BankAccount account(123456789, 1000.0, "John Doe");
  account.deposit(500.0);
  account.withdraw(200.0);
  account.printTransactionHistory();

  SavingAccount savings(987654321, 2000.0, "Jane Doe", 500.0);
  savings.deposit(300.0);
  savings.withdraw(1000.0);
  savings.withdraw(2000.0); // Should be denied
  savings.printTransactionHistory();

  CheckingAccount checking(112233445, 1500.0, "Jim Doe", 50.0, 100.0);
  checking.deposit(400.0);
  checking.withdraw(1000.0);
  checking.withdraw(2000.0); // Should charge a fee
  checking.printTransactionHistory();

  return 0;
}