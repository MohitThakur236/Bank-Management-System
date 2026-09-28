#pragma once
#include<string>
using namespace std;
class Account{
private:
    int accountNo;
    string name;
    string accountType;
    string status;
    float balance;
public:
    Account(int accountNo,string name,string accountType,string status,float balance);
    void display();
    void deposit(float amount);
    void withdraw(float amount);
    float getBalance();
    int getAccountNo();
    string getName();
    string getStatus();
    string getAccType();
};