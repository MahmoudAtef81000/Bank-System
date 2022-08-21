#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string>
#include "Screens.h"
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
#include "HelperMethods.h"

class UserChoiceValidation
{
public:

    //Methods:
    static int idClientValidation(int& id, string& stringID) {
        bool idFlag = true;
        int idIndex;
        while (idFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter your ID: ";
            getline(cin, stringID);
            if (stringID == "-1") {
                system("CLS");
                return -1;
            }
            else {
                if (!HelperMethods::isNum(stringID)) {
                    system("CLS");
                    cout << "\nEnter valid ID !\n\n";
                    idFlag = true;
                }
                else {
                    id = stoi(stringID);
                    idIndex = ExistanceCheck::idExists(id, "client");
                    if (idIndex == -1) {
                        system("CLS");
                        cout << "\nWrong ID !\n\n";
                    }
                    else {
                        system("CLS");
                        idFlag = false;
                    }
                }
            }
        }
        return idIndex;
    }
    static bool passClientValidation(int& idIndex, string& password) {
        bool passFlag = true;
        while (passFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter your password: ";
            getline(cin, password);
            if (password == "-1") {
                system("CLS");
                return false;
            }
            else {
                if (!Validation::checkPassword(password)) {
                    system("CLS");
                    cout << "\nEnter valid password !\n\n";
                    passFlag = true;
                }
                else {
                    if (!ExistanceCheck::passExists(idIndex, password, "client")) {
                        system("CLS");
                        cout << "\nWrong password !\n\n";
                        passFlag = true;
                    }
                    else {
                        system("CLS");
                        passFlag = false;
                    }
                }
            }
        }
        return true;
    }
    static bool clientChoiceHandle(Client& client, int& userChoice, string& stringUserChoice) {
        bool userFlag = true;
        while (userFlag) {
            Screens::clientMenu(client);
            getline(cin, stringUserChoice);
            if (!HelperMethods::isNum(stringUserChoice)) {
                system("CLS");
                cout << "\nEnter valid choice !\n\n";
                continue;
            }
            else {
                userChoice = stoi(stringUserChoice);
                if (!ClientManager::clientOptions(client, userChoice)) {
                    userFlag = false;
                }
            }
        }
        return false;
    }
    static int idEmployeeValidation(int& id, string& stringID) {
        bool idFlag = true;
        int idIndex;
        while (idFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter your ID: ";
            getline(cin, stringID);
            if (stringID == "-1") {
                system("CLS");
                return -1;
            }
            else {
                if (!HelperMethods::isNum(stringID)) {
                    system("CLS");
                    cout << "\nEnter valid ID !\n\n";
                    idFlag = true;
                }
                else {
                    id = stoi(stringID);
                    idIndex = ExistanceCheck::idExists(id, "employee");
                    if (idIndex == -1) {
                        system("CLS");
                        cout << "\nWrong ID !\n\n";
                    }
                    else {
                        system("CLS");
                        idFlag = false;
                    }
                }
            }
        }
        return idIndex;
    }
    static bool passEmployeeValidation(int& idIndex, string& password) {
        bool passFlag = true;
        while (passFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter your password: ";
            getline(cin, password);
            if (password == "-1") {
                system("CLS");
                return false;
            }
            else {
                if (!Validation::checkPassword(password)) {
                    system("CLS");
                    cout << "\nEnter valid password !\n\n";
                    passFlag = true;
                }
                else {
                    if (!ExistanceCheck::passExists(idIndex, password, "employee")) {
                        system("CLS");
                        cout << "\nWrong password !\n\n";
                        passFlag = true;
                    }
                    else {
                        system("CLS");
                        passFlag = false;
                    }
                }
            }
        }
        return true;
    }
    static bool employeeChoiceHandle(Employee& employee, int& userChoice, string& stringUserChoice) {
        bool userFlag = true;
        while (userFlag) {
            Screens::employeeMenu(employee);
            getline(cin, stringUserChoice);
            if (!HelperMethods::isNum(stringUserChoice)) {
                system("CLS");
                cout << "\nEnter valid choice !\n\n";
                continue;
            }
            else {
                userChoice = stoi(stringUserChoice);
                if (!EmployeeManager::employeeOptions(employee, userChoice)) {
                    userFlag = false;
                }
            }
        }
        return false;
    }
    static int idAdminValidation(int& id, string& stringID) {
        bool idFlag = true;
        int idIndex;
        while (idFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter your ID: ";
            getline(cin, stringID);
            if (stringID == "-1") {
                system("CLS");
                return -1;
            }
            else {
                if (!HelperMethods::isNum(stringID)) {
                    system("CLS");
                    cout << "\nEnter valid ID !\n\n";
                    idFlag = true;
                }
                else {
                    id = stoi(stringID);
                    idIndex = ExistanceCheck::idExists(id, "admin");
                    if (idIndex == -1) {
                        system("CLS");
                        cout << "\nWrong ID !\n\n";
                    }
                    else {
                        system("CLS");
                        idFlag = false;
                    }
                }
            }
        }
        return idIndex;
    }
    static bool passAdminValidation(int& idIndex, string& password) {
        bool passFlag = true;
        while (passFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter your password: ";
            getline(cin, password);
            if (password == "-1") {
                system("CLS");
                return false;
            }
            else {
                if (!Validation::checkPassword(password)) {
                    system("CLS");
                    cout << "\nEnter valid password !\n\n";
                    passFlag = true;
                }
                else {
                    if (!ExistanceCheck::passExists(idIndex, password, "admin")) {
                        system("CLS");
                        cout << "\nWrong password !\n\n";
                        passFlag = true;
                    }
                    else {
                        system("CLS");
                        passFlag = false;
                    }
                }
            }
        }
        return true;
    }
    static bool adminChoiceHandle(Admin& admin, int& userChoice, string& stringUserChoice) {
        bool userFlag = true;
        while (userFlag) {
            Screens::adminMenu(admin);
            getline(cin, stringUserChoice);
            if (!HelperMethods::isNum(stringUserChoice)) {
                system("CLS");
                cout << "\nEnter valid choice !\n\n";
                continue;
            }
            else {
                userChoice = stoi(stringUserChoice);
                if (!AdminManager::adminOptions(admin, userChoice)) {
                    userFlag = false;
                }
            }
        }
        return false;
    }

};

