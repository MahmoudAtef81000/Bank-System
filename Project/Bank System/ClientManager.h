#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include "ClientFileHelper.h"
#include "HelperMethods.h"
#include "ExistanceCheck.h"

using namespace std;

class ClientManager
{
public:

    //Methods:
    static void updatePassword(Client client, string password) {
        client.setPassword(password);
        Client tempClient(client.getId(), client.getName(),
            client.getPassword(), client.getBalance());
        ClientFileHelper::saveClient(tempClient);
    }
    static void updateBalance(Client& client, double balance) {
        client.deposit(balance);
        ClientFileHelper::saveClient(client);
    }
    static Client login(int index) {
        ClientFileManager c;
        vector<Client> clients = c.getAllClients();
        return clients[index];
    }
    static bool clientOptions(Client& client, int choice) {
        if (choice == 1) {
            system("CLS");
            cout << endl;
            client.checkBalance();
        }
        else if (choice == 2) {
            system("CLS");
            bool amountFlag = true;
            int amount;
            while (amountFlag) {
                cout << "\n(enter -1 to return to menu)\n";
                cout << "\nEnter amount to be deposited: ";
                string stringAmount;
                getline(cin, stringAmount);
                if (stringAmount == "-1") {
                    return true;
                }
                else if (!HelperMethods::isNum(stringAmount)) {
                    cout << "\nEnter valid amount !\n\n";
                    continue;
                }
                else {
                    amountFlag = false;
                    amount = stoi(stringAmount);
                    client.deposit(amount);
                    ClientFileHelper::saveClient(client);
                }
            }
        }
        else if (choice == 3) {
            system("CLS");
            bool amountFlag = true;
            int amount;
            while (amountFlag) {
                cout << "\n(enter -1 to return to menu)\n";
                cout << "\nEnter amount to be withdrawn: ";
                string stringAmount;
                getline(cin, stringAmount);
                if (stringAmount == "-1") {
                    return true;
                }
                else if (!HelperMethods::isNum(stringAmount)) {
                    cout << "\nEnter valid amount !\n\n";
                    continue;
                }
                else {
                    amountFlag = false;
                    amount = stoi(stringAmount);
                    client.withdraw(amount);
                    ClientFileHelper::saveClient(client);
                }
            }
        }
        else if (choice == 4) {
            system("CLS");
            bool newPassFlag = true;
            while (newPassFlag) {
                string newPass;
                cout << "\n(enter -1 to return to menu)\n";
                cout << "\nEnter new password: ";
                getline(cin, newPass);
                if (newPass == "-1") {
                    system("CLS");
                    return true;
                }
                else if (!Validation::checkPassword(newPass)) {
                    newPassFlag = true;
                }
                else {
                    newPassFlag = false;
                    updatePassword(client, newPass);
                    system("CLS");
                }
            }
        }
        else if (choice == 5) {
            system("CLS");
            int id, amount, index;
            bool idFlag = true,
                amountFlag = true;
            while (idFlag) {
                cout << "\n(enter -1 to return to menu)\n";
                cout << "\nEnter ID of the receiver: ";
                string stringID;
                getline(cin, stringID);
                if (stringID == "-1") {
                    system("CLS");
                    return false;
                }
                if (!HelperMethods::isNum(stringID)) {
                    system("CLS");
                    cout << "\nEnter valid ID !\n\n";
                }
                else {
                    id = stoi(stringID);
                    if (ExistanceCheck::idExists(id, "client") == -1 || client.getId() == id) {
                        system("CLS");
                        cout << "\nWrong ID !\n\n";
                    }
                    else {
                        index = ExistanceCheck::idExists(id, "client");
                        idFlag = false;
                    }
                }
            }
            while (amountFlag) {
                cout << "\n(enter -1 to return to menu)\n";
                cout << "\nEnter amount to be transfered: ";
                string stringAmount;
                getline(cin, stringAmount);
                if (stringAmount == "-1") {
                    return true;
                }
                else if (!HelperMethods::isNum(stringAmount)) {
                    cout << "\nEnter valid amount !\n\n";
                    continue;
                }
                else {
                    amountFlag = false;
                    amount = stoi(stringAmount);
                    Client recipient = login(index);
                    recipient.display();
                    client.transferTo(amount, recipient);
                    ClientFileHelper::saveClient(client);
                    ClientFileHelper::saveClient(recipient);
                }
            }
        }
        else if (choice == 6) {
            system("CLS");
            return false;
        }
        else {
            system("CLS");
            cout << "\n\nWrong input !\n\n";
        }
        return true;
    }

};

