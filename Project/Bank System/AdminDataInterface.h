#pragma once
#include "Admin.h"
class AdminDataInterface
{
public:

    //Methods:
    virtual void addAdmin(Admin admin) = 0;
    virtual vector<Admin> getAllAdmins() = 0;

};

