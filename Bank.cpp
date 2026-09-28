#include"Bank.h"
#include<fstream>
#include<sstream>
#include<iostream>
void Bank::createAccount(string name, int accNo, string accType, float balance){
    Account a(accNo,name,accType,"ACTIVE",balance);
    accounts.push_back(a);
    writeData();
}
void Bank::loadData(){
    ifstream file("Accounts.txt");
    string line;
    if(!file) return;
    while(getline(file,line)){
        stringstream ss(line);
        string temp;
        getline(ss,temp,'|');
        int accNo= stoi(temp);
        string name;
        getline(ss,name,'|');
        string accType;
        getline(ss,accType,'|');
        string status;
        getline(ss,status,'|');
        string t;
        getline(ss,t);
        float balance= stof(t);
        Account a(accNo,name,accType,status,balance);
        accounts.push_back(a);
    }
}
void Bank::writeData(){
    ofstream file("Accounts.txt");
    for(int i=0;i<accounts.size();i++){
        file<<accounts[i].getAccountNo()<<"|"<<accounts[i].getName()<<"|"<<accounts[i].getAccType()<<"|"<<accounts[i].getStatus()<<"|"<<accounts[i].getBalance()<<endl;
    }
}
void Bank::displayAllAccounts(){
    if(accounts.size()==0){
        cout<<"No Account Yet!!!"<<endl;
        return;
    }
    for(auto& x: accounts){
        x.display();
    }
}
Account* Bank::findAccount(int accNo){
    for(auto& x: accounts){
        if(x.getAccountNo()==accNo){
            return &x;
        } 
    }
    return nullptr;
}
long Bank::getLastTrans(){
    ifstream transaction("Transaction.txt");
    if(!transaction) return 0;
    string line;
    long trans=0;
    while(getline(transaction,line)){
        stringstream ss(line);
        string num;
        getline(ss,num,'|');
        trans= stol(num);
    }
    return trans;
}
void Bank::showLocalTime(long timestamp){
    time_t rawtime = static_cast<time_t>(timestamp);
    struct tm* localTime = localtime(&rawtime);
    
    if (localTime) {
        char buffer[80];
        strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
        cout<<buffer;
    } else {
        cout<<"Failed to convert time"<<endl;
    }
}
void Bank::writeTransData(Account* a, float amount,string s){
    long lastTrans= getLastTrans();
    ofstream transaction("Transaction.txt",ios::app);
    transaction<<lastTrans+1<<"|"<<a->getAccountNo()<<"|"<<amount<<"|"<<s<<"|"<<time(nullptr)<<"|"<<a->getBalance()<<endl;
}
void Bank::allTrans(int accNo){
    bool found= false;
    Account* a= findAccount(accNo);
    if(a==nullptr){
        cout<<"No Account Found!!!"<<endl;
        return;
    }
    ifstream file("Transaction.txt");
    if(!file){
        cout<<"No Transaction Found!!!"<<endl;
        return;
    }
    string line;
    while(getline(file,line)){
        stringstream ss(line);
        string transId;
        getline(ss,transId,'|');
        string accouNo;
        getline(ss,accouNo,'|');
        int accountNo= stoi(accouNo);
        if(accountNo==accNo){
            found=true;
            string amt;
            getline(ss,amt,'|');
            string type;
            getline(ss,type,'|');
            string time;
            getline(ss,time,'|');
            string balance;
            getline(ss,balance);
            cout<<"Transaction Id: "<<transId<<" | "<<"Account No: "<<accNo<<" | "<<"Amount: "<<amt<<" | "<<type<<" | "<<"Time: ";
            showLocalTime(stol(time));
            cout<<" | "<<"Balance: "<<balance<<endl;
        }
    }
    if(!found) cout<<"No Transaction Found!!!"<<endl;
}
