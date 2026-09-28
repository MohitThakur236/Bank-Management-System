// #include<Transaction.h>
// #include<Account.h>
// #include<fstream>
// #include<sstream>
// int Transaction::getTransId(){
//     return this->TransactionId;
// }
// int Transaction::getAccNo(){
//     return this->accountNo;
// }
// string Transaction::getTransType(){
//     return this->transactionType;
// }
// float Transaction::getAmountChange(){
//     return this->amountChange;
// }
// time_t Transaction::getTime(){
//     return this->time;
// }
// float Transaction::getBalance(){
//     return this->balance;
// }
// long Transaction::getLastTrans(){
//     ifstream transaction("Transaction.txt");
//     if(!transaction) return 0;
//     string line;
//     long transaction;
//     while(getline(transaction,line)){
//         stringstream ss(line);
//         string num;
//         getline(num,ss,'|');
//         transaction= stol(num);
//     }
//     return transaction;
// }
// void Transaction::writeTransData(Account* a, float amount,string s){
//     long lastTrans= getLastTrans();
//     ofstream transaction("Transaction.txt",ios::app);
//     transaction<<lastTrans+1<<" | "<<a->getAccountNo()<<" | "<<amount<<" | "<<s<<" | "<<time(nullptr)<<a->getBalance<<endl;
// }