#pragma once
#include "AdminFileHelper.h"
#include "HelperMethods.h"
#include "ExistanceCheck.h"
#include "EmployeeManager.h"


class AdminManager
{
public:

    //Methods:
    static bool newEmployee(Admin admin) {
        string stringID, name, password, stringSalary;
        int id;
        double salary;
        bool nameFlag = true,
            passFlag = true,
            salaryFlag = true;
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
        while (salaryFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter new salary: ";
            getline(cin, stringSalary);
            if (stringSalary == "-1") {
                system("CLS");
                return false;
            }
            if (!HelperMethods::isFloatNum(stringSalary)) {
                system("CLS");
                cout << "\nEnter valid salary !\n\n";
            }
            else {
                salary = stod(stringSalary);
                if (!Validation::checkSalary(salary)) {
                    system("CLS");
                    cout << "\nEnter valid salary !\n\n";
                }
                else {
                    salaryFlag = false;
                    system("CLS");
                }
            }
        }
        id = EmployeeFileHelper::getLastId();
        Employee employee(id, name, password, salary);
        admin.addEmployee(employee);
        system("CLS");
        return true;

    }
    static void listAllEmployees(Admin admin) {
        admin.listAllEmployees();
    }
    static bool searchForEmployee(Admin admin) {
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
                if (ExistanceCheck::idExists(id, "employee") == -1) {
                    system("CLS");
                    cout << "\nWrong ID !\n\n";
                }
                else {
                    idFlag = false;
                }
            }
        }
        system("CLS");
        admin.listEmployee(id);
        return true;
    }
    static bool removeEmployee(Admin admin) {
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
                    if (ExistanceCheck::idExists(id, "employee") == -1) {
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
        admin.listEmployee(id);
        while (choiceFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter \"Y\" to remove employee: ";
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
        admin.removeEmployee(id);
        return true;
    }
    static bool editEmployeeInfo(Admin admin) {
        string stringID, name, password, stringSalary;
        int id;
        double salary;
        bool idFlag = true,
            nameFlag = true,
            passFlag = true,
            salaryFlag = true;
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
                    if (ExistanceCheck::idExists(id, "employee") == -1) {
                        system("CLS");
                        cout << "\nWrong ID !\n\n";
                    }
                    else {
                        idFlag = false;
                    }
                }
            }
        }
        admin.listEmployee(id);
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
        while (salaryFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter new salary: ";
            getline(cin, stringSalary);
            if (stringSalary == "-1") {
                system("CLS");
                return false;
            }
            else {
                if (!HelperMethods::isFloatNum(stringSalary)) {
                    system("CLS");
                    cout << "\nEnter valid salary !\n\n";
                }
                else {
                    salary = stod(stringSalary);
                    if (!Validation::checkSalary(salary)) {
                        system("CLS");
                        cout << "\nEnter valid salary !\n\n";
                    }
                    else {
                        salaryFlag = false;
                    }
                }
            }
        }
        admin.editEmployee(id, name, password, salary);
        return true;
    }
    static bool newAdmin() {
        string stringID, name, password, stringSalary;
        int id = 1;
        double salary;
        bool nameFlag = true,
            passFlag = true,
            salaryFlag = true;
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
        while (salaryFlag) {
            cout << "\n(enter -1 to return to menu)\n";
            cout << "\nEnter new salary: ";
            getline(cin, stringSalary);
            if (stringSalary == "-1") {
                system("CLS");
                return false;
            }
            if (!HelperMethods::isFloatNum(stringSalary)) {
                system("CLS");
                cout << "\nEnter valid salary !\n\n";
            }
            else {
                salary = stod(stringSalary);
                if (!Validation::checkSalary(salary)) {
                    system("CLS");
                    cout << "\nEnter valid salary !\n\n";
                }
                else {
                    salaryFlag = false;
                    system("CLS");
                }
            }
        }
        Admin admin(id, name, password, salary);
        AdminFileManager a;
        a.addAdmin(admin);
        system("CLS");
        return true;

    }
    static Admin login(int index) {
        AdminFileManager a;
        vector<Admin> admins = a.getAllAdmins();
        return admins[index];
    }
    static bool adminOptions(Admin admin, int choice) {
        if (choice == 1) {
            system("CLS");
            EmployeeManager::newClient(admin);
        }
        else if (choice == 2) {
            system("CLS");
            if (!EmployeeManager::searchForClient(admin)) {
                system("CLS");
                return true;
            }
        }
        else if (choice == 3) {
            system("CLS");
            if (!EmployeeManager::editClientInfo(admin)) {
                system("CLS");
                return true;
            }
        }
        else if (choice == 4) {
            system("CLS");
            if (!EmployeeManager::removeClient(admin)) {
                system("CLS");
                return true;
            }
        }
        else if (choice == 5) {
            system("CLS");
            EmployeeManager::listAllClients(admin);
        }
        else if (choice == 6) {
            system("CLS");
            newEmployee(admin);
        }
        else if (choice == 7) {
            system("CLS");
            if (!searchForEmployee(admin)) {
                system("CLS");
                return true;
            }
        }
        else if (choice == 8) {
            system("CLS");
            if (!editEmployeeInfo(admin)) {
                system("CLS");
                return true;
            }
        }
        else if (choice == 9) {
            system("CLS");
            if (!removeEmployee(admin)) {
                system("CLS");
                return true;
            }
        }
        else if (choice == 10) {
            system("CLS");
            listAllEmployees(admin);
        }
        else if (choice == 11) {
            system("CLS");
            newAdmin();
        }
        else if (choice == 12) {
            system("CLS");
            cout << endl;
            admin.display();
        }
        else if (choice == 13) {
            system("CLS");
            ClientFileHelper::clearFile();
        }
        else if (choice == 14) {
            system("CLS");
            EmployeeFileHelper::clearFile();
        }
        else if (choice == 15) {
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

