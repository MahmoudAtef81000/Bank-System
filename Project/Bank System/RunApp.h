#pragma once
#include "UserChoiceValidation.h"

using namespace std;

class RunApp
{
public:

    //Methods:
    static void runApp() {
        bool flag = true;
        while (flag) {
            flag = true;
            Screens::welcome();
            int choice, id, userChoice, idIndex;
            string stringChoice, stringID, stringUserChoice, password;
            getline(cin, stringChoice);
            if (!HelperMethods::isNum(stringChoice)) {
                system("CLS");
                cout << "\nEnter valid choice !\n\n";
                continue;
            }
            choice = stoi(stringChoice);
            if (choice == 1) {
                system("CLS");
                flag = false;
                idIndex = UserChoiceValidation::idClientValidation(id, stringID);
                if (idIndex == -1) {
                    flag = true;
                    continue;
                }
                if (!UserChoiceValidation::passClientValidation(idIndex, password)) {
                    flag = true;
                    continue;
                }
                Client client = ClientManager::login(idIndex);
                system("CLS");
                if (!UserChoiceValidation::clientChoiceHandle(client, userChoice, stringUserChoice)) {
                    flag = true;
                    continue;
                }
            }
            else if (choice == 2) {
                system("CLS");
                flag = false;
                idIndex = UserChoiceValidation::idEmployeeValidation(id, stringID);
                if (idIndex == -1) {
                    flag = true;
                    continue;
                }
                if (!UserChoiceValidation::passEmployeeValidation(idIndex, password)) {
                    flag = true;
                    continue;
                }
                Employee employee = EmployeeManager::login(idIndex);
                system("CLS");
                if (!UserChoiceValidation::employeeChoiceHandle(employee, userChoice, stringUserChoice)) {
                    flag = true;
                    continue;
                }
            }
            else if (choice == 3) {
                system("CLS");
                flag = false;
                idIndex = UserChoiceValidation::idAdminValidation(id, stringID);
                if (idIndex == -1) {
                    flag = true;
                    continue;
                }
                if (!UserChoiceValidation::passAdminValidation(idIndex, password)) {
                    flag = true;
                    continue;
                }
                Admin admin = AdminManager::login(idIndex);
                system("CLS");
                if (!UserChoiceValidation::adminChoiceHandle(admin, userChoice, stringUserChoice)) {
                    flag = true;
                    continue;
                }
            }
            else if (choice == 4) {
                system("CLS");
                cout << "\n\nGOODBYE !\n\n";
                return;
            }
            else {
                system("CLS");
                cout << "\nWrong input !\n\n";
                flag = true;
            }
        }
    }
};

