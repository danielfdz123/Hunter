//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//December 7, 2022
//Project 3b

#include <iostream>
#include <string>
#include "Bank.hpp"
#include "Account.hpp"

Bank::Bank() 
{
    num = 0;
}

//Creates a bank account using first name, last name, and a pin number
std::string Bank::createAccount(std::string fName, std::string lName, std::string pin) 
{
    if(num < 200) 				    //Task tells us size is 200
    {
        Accounts[num].setFirstName(fName);	    //Acc should be integer values
        Accounts[num].setLastName(lName);
        Accounts[num].setPin(pin);
        num++;
        return Accounts[num - 1].getAccountNumber();
    }
    else 
    {
        return "-1";
    }
}

//Removes any unecessary account 
bool Bank::removeAccount(std::string remove) 
{
    for(int i = 0; i < num; i++) 
    {
        if(Accounts[i].getAccountNumber() == remove) 
        {
            for(int j = i; j < num - 1; j++) 
            {
                Accounts[j] = Accounts[j + 1];
            }
            num--;
            return true;
        }
    }
    return false;
}

//Withdraws money from the account
bool Bank::withdraw(int moneyAmount, std::string accountNumber, std::string pin) 
{
    for(int i = 0; i < num; i++) 
    {
        if(Accounts[i].getAccountNumber() == accountNumber) 
        {
            if(Accounts[i].getPin() == pin) 
            {
                if(Accounts[i].getBalance() >= moneyAmount) 
                {
                    Accounts[i].transaction(-moneyAmount);
                    return true;
                }
            }
        }
    }
    return false;
}

//Deposits money into account
bool Bank::deposit(int moneyAmount, std::string accountNumber, std::string pin) 
{
    for(int i = 0; i < num; i++) 
    {
        if(Accounts[i].getAccountNumber() == accountNumber) 
        {
            if(Accounts[i].getPin() == pin) 
            {
                Accounts[i].transaction(moneyAmount);

                return true;
            }
        }
    }
    return false;
}

//Gets account balance
int Bank::getAccountBalance(std::string accountNumber, std::string pin) 
{
    for(int i = 0; i < num; i++) 
    {
        if(Accounts[i].getAccountNumber() == accountNumber) 
        {
            if(Accounts[i].getPin() == pin) 
            {
                return Accounts[i].getBalance();
            }
        }
    }
    return -1;
}
