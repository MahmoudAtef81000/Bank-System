#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "AdminDataInterface.h"


class AdminFileManager : public AdminDataInterface
{
public:

    //Methods:
    vector<Admin>getAllAdmins() {
        vector<Admin> admins;
        ifstream readFile("Admins.txt");
        string lineData;
        while (getline(readFile, lineData)) {
            admins.push_back(Parser::parseToEmployee<Admin>(lineData));
        }
        readFile.close();
        return admins;
    }
    void addAdmin(Admin admin) {
        ofstream writeFile("Admins.txt");
        writeFile << admin.getId() << ",";
        writeFile << admin.getName() << ",";
        writeFile << admin.getPassword() << ",";
        writeFile << admin.getSalary();
        writeFile.close();
    }
    void removeAllAdmins() {
        ofstream writeFile("Admins.txt");
        writeFile << "";
        writeFile.close();
    }

};

