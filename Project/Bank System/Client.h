#pragma once
#include "Person.h"



class Client : public Person
{
private:

    //Attributes:
    double balance;

public:

    //Constructors:
    Client() {
        balance = 0.0;
    }
    Client(int id, string name, string password,
        double balance) :Person(id, name, password) {
        this->balance = balance;
    }

    //Setters:
    void setBalance(double balance) {
        this->balance = balance;
    }

    //Getters:
    double getBalance() {
        return balance;
    }

    //Methods:
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "invalid amount ! ";
            return;
        }
        balance += amount;
    }
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "amount exceeds current balance !\n";
        }
        else if (amount <= 0) {
            cout << "invalid amount ! ";
        }
        else {
            balance -= amount;
        }
    }
    void transferTo(double amount, Client& recipient) {
        if (amount > balance) {
            cout << "amount exceeds current balance !\n";
        }
        else if (amount <= 0) {
            cout << "invalid amount ! ";
        }
        else {
            balance -= amount;
            recipient.deposit(amount);
        }
    }
    void checkBalance() {
        cout << "Balance = " << balance << endl;
    }
    void display() {
        cout << "Client Info:\n------------\n";
        Person::display();
        cout << "Balance: " << balance << endl;
        cout << "================================\n";
    }

    //Destructor:
    ~Client() {

    }

};

