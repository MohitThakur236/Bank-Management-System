#include "Bank.h"
#include<iostream>
using namespace std;
float getPositiveFloat(){
    while(true){
        string input;
        getline(cin,input);
        try{
            size_t pos;
            float value= stof(input,&pos);
            if(pos==input.size() && value>0) return value;
        }
        catch(...){}
        cout<<"Enter Positive Integer: ";
    }
}
int getPositiveInteger(){
    while(true){
        string input;
        getline(cin,input);
        try{
            size_t pos;
            int value= stoi(input,&pos);
            if(pos==input.size() && value>0) return value;
        }
        catch(...){}
        cout<<"Enter Positive Integer: ";
    }
}
bool validOwnerName(string name){
    int count=0;
    for(int i=0;i<name.size();i++){
        if(name[i]==' ') count++;
    }
    if(name.size()-count<3) return false;
    for(int i=0;i<name.size();i++){
        if(!isalpha(name[i]) && name[i]!=' ') return false;
    }
    return true;
}
int main(){
    Bank bank;
    bank.loadData();
    int val;
    while(true){
        cout<<endl;
        cout<<"====== Bank Management System ======\n";
        cout<<"       1. Create Account\n";
        cout<<"       2. Display All Accounts\n";
        cout<<"       3. Deposit  Money\n";
        cout<<"       4. Withdraw  Money\n";
        cout<<"       5. Check Balance\n";
        cout<<"       6. All Transactions of an Account\n";
        cout<<"       7. Bank Transfer\n";
        cout<<"       8. Exit\n";
        cout<<"Enter your choice: ";
        val=getPositiveInteger();
        if(val==1){
            int accNo;
            while(true){
                cout<<"Enter Account Number: ";
                accNo= getPositiveInteger();
                if(bank.findAccount(accNo)==nullptr) break;
                cout<<"Account number already exist!!!\n";
            }
            string name;
            cout<<"Enter your name: ";
            getline(cin,name);
            while(!validOwnerName(name)){
                cout<<"Enter Corret name: ";
                getline(cin,name);
            }
            string accType;
            int type;
            cout<<"Enter Account Type\n";
            cout<<"1. SAVING\n";
            cout<<"2. CURRENT\n";
            cout<<"Enter your choice: ";
            type= getPositiveInteger();
            while(type<1 || type>2){
                cout<<"Enter Correct Type: ";
                type= getPositiveInteger();
            }
            if(type==1) accType= "SAVING";
            else if(type==2) accType= "CURRENT";
            float balance;
            cout<<"Enter amount to deposit while Opening: ";
            balance= getPositiveFloat();
            bank.createAccount(name, accNo,accType,balance);
            cout<<"Account Creation Successful!!!\n";
        }
        else if(val==2){
            bank.displayAllAccounts();
        }
        else if(val==3){
            int accNo;
            cout<<"Enter Account Number: ";
            accNo= getPositiveInteger();
            Account* a= bank.findAccount(accNo);
            if(a==nullptr){
                cout<<"Account Doesn't Exist!!!\n";
            }
            else{
                float amount;
                cout<<"Enter Amount to deposit: ";
                amount= getPositiveFloat();
                a->deposit(amount);
                cout<<"Deposit Successful!!!\n";
                cout<<"Current Balance: "<<a->getBalance()<<endl;
                bank.writeData();
                bank.writeTransData(a,amount,"DEPOSIT");
            }
        }
        else if(val==4){
            int accNo;
            cout<<"Enter Account Number: ";
            accNo= getPositiveInteger();
            Account* a= bank.findAccount(accNo);
            if(a==nullptr){
                cout<<"Account Doesn't Exist!!!\n";
            }
            else{
                float amount;
                cout<<"Enter Amount to withdraw: ";
                amount= getPositiveFloat();
                try{
                    a->withdraw(amount);
                    cout<<"Withdrawl Successful!!!\n";
                    cout<<"Current Balance: "<<a->getBalance()<<endl;
                    bank.writeData();
                    bank.writeTransData(a,amount,"WITHDRAW");
                }
                catch(const exception& e){
                    cout<<e.what();
                }
            }
        }
        else if(val==5){
            int accNo;
            cout<<"Enter Account Number: ";
            accNo= getPositiveInteger();
            Account* a= bank.findAccount(accNo);
            if(a==nullptr){
                cout<<"Account Doesn't Exist!!!\n";
            }
            else{
                cout<<"Balance: "<<a->getBalance()<<endl;
            }
        }
        else if(val==6){
            int accNo;
            cout<<"Enter Account Number: ";
            accNo= getPositiveInteger();
            bank.allTrans(accNo);
        }
        else if(val==7){
            int selfAccNo;
            cout<<"Enter your Account Number: ";
            selfAccNo= getPositiveInteger();
            Account* s= bank.findAccount(selfAccNo);
            if(s==nullptr){
                cout<<"Account Doesn't Exists!!!\n";
            }
            else{
                int accNo;
                cout<<"Enter Account Number Whom to Transfer: ";
                accNo=getPositiveInteger();
                Account* a= bank.findAccount(accNo);
                if(a==nullptr){
                    cout<<"Account Doesn't Exists!!!\n";
                }
                else{
                    float amount;
                    cout<<"Enter Amount to Transfer: ";
                    amount= getPositiveFloat();
                    if(amount>s->getBalance()){
                        cout<<"Isufficient Balance!!!\n";
                    }
                    else{
                        s->withdraw(amount);
                        a->deposit(amount);
                        cout<<"Transfer Successfull!!!\n";
                        bank.writeData();
                        bank.writeTransData(s,amount,"Transfer Out");
                        bank.writeTransData(a,amount,"Transfer In");
                    }
                }
            }
            
        }
        else if(val==8){
            break;
        }
        else{
            cout<<"<-----Enter Correct Input----->\n";
        }
    }
}