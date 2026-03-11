//Daniel Andres Fernandez
//daniel.fernandez16@myhunter.cuny.edu
//November 2022
//Project 3 Task A 

#include <iostream>
#include <string>
#include "Account.hpp"

using namespace std;

string Account::generateAccountNumber()
{
    std::string an_str = "";
    for(int i{0}; i < 8; i++ ){
        int temp = rand() % 10;
        an_str += std::to_string(temp);
    }
    return an_str;
}

Account::Account() 
{
    firstName = "anonymous";
    lastName = "anonymous";
    pin = "0000";
    accountNumber = generateAccountNumber();
    accountBalance = 0;
}

Account::Account(std::string FName, std::string LName, std::string pin) 
{
    firstName = FName;
    lastName = LName;

    if(pin.length() == 4) 
    {
        pin = pinNumber;
    } 
    else 
    {
        pin = "0000";
    }

    accountNumber = generateAccountNumber();
    accountBalance = 0;
}

void Account::setFirstName(std::string name) 
{
    firstName = name;
}

void Account::setLastName(std::string name) 
{
    lastName = name;
}

bool Account::setPin(std::string setpin) 
{
    if(pin.length() == 4) 
    {
        pin = setpin;
        return true;
    } 
    else 
    {
        return false;
    }
}

std::string Account::getFirstName() 
{
    return firstName;
}

std::string Account::getLastName() 
{
    return lastName;
}

std::string Account::getAccountNumber() 
{
    return accountNumber;
}

std::string Account::getPin() 
{
    return pin;
}

int Account::getBalance()
{
    return accountBalance;
}

bool Account::transaction(int totalAmount) 
{
    if(accountBalance + totalAmount < 0) 
    {
        return false;
    } 
    else 
    {
        accountBalance += totalAmount;
        return true;
    }
}
