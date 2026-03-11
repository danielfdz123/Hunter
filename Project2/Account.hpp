//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//November 2022
//Project 3 Task A 

#include <iostream>
#include <string>

#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

using namespace std;

class Account 
{
    private:
        std::string firstName;
        std::string lastName;
        std::string pin;
        std::string accountNumber;
        int accountBalance;
        std::string generateAccountNumber();
    
    public:
        Account();
        Account(std::string infoFirstName, std::string infoLastName, std::string pinNumber);

    //Setters
        void setFirstName(std::string name);
        void setLastName(std::string name);
        bool setPin(std::string pin);

    //Getters
        std::string getFirstName();
        std::string getLastName();
        std::string getAccountNumber();
        std::string getPin();
        int getBalance();
        bool transaction(int totalAmount);
};

#endif
