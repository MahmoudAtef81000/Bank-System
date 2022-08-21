#pragma once
#include "Employee.h"

class EmployeeDataInterface
{
public:

    //Methods:
    virtual void addEmployee(Employee employee) = 0;
    virtual vector<Employee> getAllEmployees() = 0;
    virtual void removeEmployee(int id) = 0;
    virtual void removeAllEmployees() = 0;

};

