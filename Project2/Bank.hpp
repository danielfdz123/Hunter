//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//December 7, 2022
//Project 3b

#include <iostream>
#include <string>
#include "Account.hpp"

class Account;

class Bank {
private:
    Account Accounts[200];
    int num;
public:
    Bank();
    std::string createAccount(std::string fName, std::string lName, std::string pin);
    bool removeAccount(std::string remove);
    bool withdraw(int moneyAmount, std::string accountNumber, std::string pin); 
    bool deposit(int moneyAmount, std::string accountNumber, std::string pin);
    int getAccountBalance(std::string accountNumber, std::string pin);
};
