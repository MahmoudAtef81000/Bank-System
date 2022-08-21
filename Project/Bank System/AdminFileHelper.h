#pragma once
#include "AdminFileManager.h"

class AdminFileHelper
{
public:

    //Methods:
    static void getAdmins() {
        AdminFileManager a;
        vector<Admin> admins = a.getAllAdmins();
        int adminsSize = admins.size();
        for (int i = 0; i < adminsSize; i++) {
            admins[i].display();
        }
    }
    static void clearFile() {
        AdminFileManager a;
        a.removeAllAdmins();
    }

};

