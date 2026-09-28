Bank Management System

A console-based Bank Management System developed in C++ that allows users to create and manage bank accounts, perform deposits and withdrawals, check balances, and view transaction history.

Features:-
* Create a new bank account
* Display all bank accounts
* Deposit money
* Withdraw money
* Check account balance
* View transaction history for an account
* Unique account number validation
* Persistent account and transaction data using text files
* Input validation
* Exception handling for invalid withdrawals and insufficient balance
* Transaction timestamps

Project Structure:-

Bank-Management-System/
│
├── Account.h
├── Account.cpp
├── Bank.h
├── Bank.cpp
├── main.cpp
├── Accounts.txt
├── Transaction.txt
├── .gitignore
└── README.md

Concepts Used:-
* C++
* Object-Oriented Programming
* Encapsulation
* Classes and Objects
* STL vector
* File Handling
* fstream
* stringstream
* Exception Handling
* Pointers
* Input Validation
* Time Handling
* Multi-file C++ Project Structure

How to Run

Compile all .cpp files together:

g++ *.cpp -o main

Run the program:

./main

Menu

====== Bank Management System ======
       1. Create Account
       2. Display All Accounts
       3. Deposit Money
       4. Withdraw Money
       5. Check Balance
       6. All Transactions of an Account
       7. Exit

Data Storage:-

The project uses text files for persistent storage:

* Accounts.txt — stores account information and balances.
* Transaction.txt — stores transaction IDs, account numbers, transaction amounts, transaction types, timestamps, and balances after transactions.

Future Improvements:-
* Add account deletion/deactivation
* Add PIN/password-based authentication
* Add transfer money functionality
* Improve transaction management using a dedicated Transaction class
* Add more advanced data validation
* Use a database for persistent storage

C++ | OOP | DSA | Problem Solving