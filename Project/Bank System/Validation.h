#pragma once
#include <iostream>
#include <string>

using namespace std;

class Validation
{
public:

    //Methods:
    static bool checkName(string name) {
        if (!(name.size() >= 3 && name.size() <= 20)) {
            cout << "\ninvalid name size ! \" enter between 5 and 20 characters \"\n";
            return false;
        }
        for (int i = 0; i < name.size(); i++) {
            if (!(name[i] >= 'A' && name[i] <= 'z')) {
                cout << "\ninvalid name format ! \" enter alphabet characters only \"\n";
                return false;
            }
        }
        return true;
    }
    static bool checkPassword(string pass) {
        if (!(pass.size() >= 5 && pass.size() <= 20)) {
            cout << "\ninvalid password size ! \" enter between 5 and 20 characters \"\n";
            return false;
        }
        for (int i = 0; i < pass.size(); i++) {
            if (pass[i] == ' ') {
                cout << "\ninvalid password format ! \" don't enter spaces \"\n";
                return false;
            }
        }
        return true;
    }
    static bool checkBalance(double balance) {
        if (balance < 1500) {
            cout << "\ninvalid balance ! \" enter 1500 or higher \"\n";
            return false;
        }
        return true;
    }
    static bool checkSalary(double salary) {
        if (salary < 5000) {
            cout << "\ninvalid salary ! \" enter 5000 or higher \"\n";
            return false;
        }
        return true;
    }
};

