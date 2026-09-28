#pragma once
#include "Account.h"
#include<vector>
class Bank{
private:
    vector<Account> accounts;
public:
    void createAccount(string name, int accNo, string accType,float balance);
    void loadData();
    void writeData();
    void displayAllAccounts();
    Account* findAccount(int accNo);
    long getLastTrans();
    void writeTransData(Account* a, float amount,string s);
    void showLocalTime(long timestamp);
    void allTrans(int accNo);
};