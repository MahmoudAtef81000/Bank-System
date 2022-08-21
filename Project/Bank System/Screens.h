#pragma once
#include <iostream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

using namespace std;

class Screens
{
public:

    //Methods:
    static void bankName() {
        cout << "\n=========================";
        cout << "\n\nGRINGOTTS WIZARDING BANK\n\n";
        cout << "=========================\n\n\n\n";
    }
    static void welcome() {
        bankName();
        cout << "What are you ?\n\n";
        cout << "1 - Client\n2 - Employee\n3 - Admin\n4 - Exit system\n\nYour answer: ";
    }
    static void clientMenu(Client client) {
        cout << "\n\nWhat do you want to do, " << client.getName() << " ?\n\n";
        cout << "1 - Check balance\n";
        cout << "2 - Deposit\n";
        cout << "3 - Withdraw\n";
        cout << "4 - Update password\n";
        cout << "5 - Transfer money to another client\n";
        cout << "6 - Log out\n\nYour answer: ";
    }
    static void employeeMenu(Employee employee) {
        cout << "\n\nWhat do you want to do, " << employee.getName() << " ?\n\n";
        cout << "1 - Add new client\n";
        cout << "2 - Search for a client\n";
        cout << "3 - Edit info of a client\n";
        cout << "4 - remove existing client\n";
        cout << "5 - List all clients\n";
        cout << "6 - Display my info\n";
        cout << "7 - Clear clients file\n";
        cout << "8 - Log out\n\nYour answer: ";
    }
    static void adminMenu(Admin admin) {
        cout << "\n\nWhat do you want to do, " << admin.getName() << " ?\n\n";
        cout << "1 - Add new client\n";
        cout << "2 - Search for a client\n";
        cout << "3 - Edit info of a client\n";
        cout << "4 - remove existing client\n";
        cout << "5 - List all clients\n";
        cout << "6 - Add new employee\n";
        cout << "7 - Search for an employee\n";
        cout << "8 - Edit info of an employee\n";
        cout << "9 - remove existing employee\n";
        cout << "10 - List all employees\n";
        cout << "11 - Assign new admin\n";
        cout << "12 - Display my info\n";
        cout << "13 - Clear clients file\n";
        cout << "14 - Clear employees file\n";
        cout << "15 - Log out\n\nYour answer: ";
    }

};

