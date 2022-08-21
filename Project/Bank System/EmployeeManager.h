#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include "EmployeeFileHelper.h"
#include "HelperMethods.h"
#include "ExistanceCheck.h"

class EmployeeManager
{
public:

    //Methods:
    static bool newClient(Employee employee) {
        string stringID, name, password, stringBalance;
        int id;
        double balance;
        bool nameFlag = true,
            passFlag = true,
            balanceFlag = true;
        while (nameFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter new name: ";
            getline(cin, name);
            if (name == "-1") {
                system("CLS");
                return false;
            }
            if (!Validation::checkName(name)) {
                system("CLS");
                cout << "\nEnter valid name !\n\n";
            }
            else {
                nameFlag = false;
                system("CLS");
            }
        }
        while (passFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter new password: ";
            getline(cin, password);
            if (password == "-1") {
                system("CLS");
                return false;
            }
            if (!Validation::checkPassword(password)) {
                system("CLS");
                cout << "\nEnter valid password !\n\n";
            }
            else {
                passFlag = false;
                system("CLS");
            }
        }
        while (balanceFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter new balance: ";
            getline(cin, stringBalance);
            if (stringBalance == "-1") {
                system("CLS");
                return false;
            }
            if (!HelperMethods::isFloatNum(stringBalance)) {
                system("CLS");
                cout << "\nEnter valid balance !\n\n";
            }
            else {
                balance = stod(stringBalance);
                if (!Validation::checkBalance(balance)) {
                    system("CLS");
                    cout << "\nEnter valid balance !\n\n";
                }
                else {
                    balanceFlag = false;
                    system("CLS");
                }
            }
        }
        id = ClientFileHelper::getLastId();
        Client client(id, name, password, balance);
        employee.addClient(client);
        system("CLS");
        return true;
    }
    static void listAllClients(Employee employee) {
        employee.listAllClients();
    }
    static bool searchForClient(Employee employee) {
        string stringID;
        int id;
        bool idFlag = true;
        while (idFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter ID: ";
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
                if (ExistanceCheck::idExists(id, "client") == -1) {
                    system("CLS");
                    cout << "\nWrong ID !\n\n";
                }
                else {
                    idFlag = false;
                }
            }
        }
        system("CLS");
        employee.listClient(id);
        return true;
    }
    static bool removeClient(Employee employee) {
        string stringID, choice;
        int id;
        bool idFlag = true,
            choiceFlag = true;
        while (idFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter ID: ";
            getline(cin, stringID);
            if (stringID == "-1") {
                system("CLS");
                return false;
            }
            else {
                if (!HelperMethods::isNum(stringID)) {
                    system("CLS");
                    cout << "\nEnter valid ID !\n\n";
                }
                else {
                    id = stoi(stringID);
                    if (ExistanceCheck::idExists(id, "client") == -1) {
                        system("CLS");
                        cout << "\nWrong ID !\n\n";
                    }
                    else {
                        idFlag = false;
                    }
                }
            }
        }
        system("CLS");
        employee.listClient(id);
        while (choiceFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter \"Y\" to remove client: ";
            getline(cin, choice);
            if (choice == "-1") {
                system("CLS");
                return false;
            }
            else {
                if (choice == "" || (choice != "Y" && choice != "y")) {
                    system("CLS");
                    cout << "\nEnter valid choice !\n\n";
                }
                else {
                    system("CLS");
                    choiceFlag = false;
                }
            }
        }
        employee.removeClient(id);
        return true;
    }
    static bool editClientInfo(Employee employee) {
        string stringID, name, password, stringBalance;
        int id;
        double balance;
        bool idFlag = true,
            nameFlag = true,
            passFlag = true,
            balanceFlag = true;
        while (idFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter ID: ";
            getline(cin, stringID);
            if (stringID == "-1") {
                system("CLS");
                return false;
            }
            else {
                if (!HelperMethods::isNum(stringID)) {
                    system("CLS");
                    cout << "\nEnter valid ID !\n\n";
                }
                else {
                    id = stoi(stringID);
                    if (ExistanceCheck::idExists(id, "client") == -1) {
                        system("CLS");
                        cout << "\nWrong ID !\n\n";
                    }
                    else {
                        idFlag = false;
                    }
                }
            }
        }
        employee.listClient(id);
        while (nameFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter new name: ";
            getline(cin, name);
            if (name == "-1") {
                system("CLS");
                return false;
            }
            else {
                if (!Validation::checkName(name)) {
                    system("CLS");
                    cout << "\nEnter valid name !\n\n";
                }
                else {
                    nameFlag = false;
                }
            }
        }
        while (passFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter new password: ";
            getline(cin, password);
            if (password == "-1") {
                system("CLS");
                return false;
            }
            else {
                if (!Validation::checkPassword(password)) {
                    system("CLS");
                    cout << "\nEnter valid password !\n\n";
                }
                else {
                    passFlag = false;
                }
            }
        }
        while (balanceFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter new balance: ";
            getline(cin, stringBalance);
            if (stringBalance == "-1") {
                system("CLS");
                return false;
            }
            else {
                if (!HelperMethods::isFloatNum(stringBalance)) {
                    system("CLS");
                    cout << "\nEnter valid balance !\n\n";
                }
                else {
                    balance = stod(stringBalance);
                    balanceFlag = false;
                }
            }
        }
        employee.editClient(id, name, password, balance);
        return true;
    }
    static Employee login(int index) {
        EmployeeFileManager e;
        vector<Employee> employees = e.getAllEmployees();
        return employees[index];
    }
    static bool employeeOptions(Employee employee, int choice) {
        if (choice == 1) {
            system("CLS");
            newClient(employee);
        }
        else if (choice == 2) {
            system("CLS");
            if (!searchForClient(employee)) {
                system("CLS");
                return true;
            }
        }
        else if (choice == 3) {
            system("CLS");
            if (!editClientInfo(employee)) {
                system("CLS");
                return true;
            }
        }
        else if (choice == 4) {
            system("CLS");
            if (!removeClient(employee)) {
                system("CLS");
                return true;
            }
        }
        else if (choice == 5) {
            system("CLS");
            listAllClients(employee);
        }
        else if (choice == 6) {
            system("CLS");
            cout << endl;
            employee.display();
        }
        else if (choice == 7) {
            system("CLS");
            ClientFileHelper::clearFile();
        }
        else if (choice == 8) {
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

