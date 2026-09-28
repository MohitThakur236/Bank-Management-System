#include "Account.h"
#include<iostream>
#include<stdexcept>
Account::Account(int acc,string name,string aType,string status,float balance)
    : accountNo(acc),name(name),accountType(aType),status(status),balance(balance) {}
void Account::display(){
    cout<<"Account Number: "<<this->accountNo<<endl;
    cout<<"Owner name: "<<this->name<<endl;
    cout<<"Account Type: "<<this->accountType<<endl;
    cout<<"Balance: "<<this->balance<<endl;
    cout<<"Status: "<<this->status<<endl;
    cout<<endl;
}
void Account::deposit(float amount){
    this->balance+=amount;
}
void Account::withdraw(float amount){
    if(amount>this->balance) throw invalid_argument("Insufficient Balance!!!\n");
    this->balance-=amount;
}
float Account::getBalance(){
    return this->balance;
}
int Account::getAccountNo(){
    return this->accountNo;
}
string Account::getName(){
    return this->name;
}
string Account::getStatus(){
    return this->status;
}
string Account::getAccType(){
    return this->accountType;
}