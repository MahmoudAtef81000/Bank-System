#pragma once
#include "EmployeeFileManager.h"

class EmployeeFileHelper
{
public:

    //Methods:
    static int getLastId() {
        EmployeeFileManager e;
        vector<Employee> employees = e.getAllEmployees();
        int employeesSize = employees.size(), id;
        if (!employeesSize) {
            id = 3;
        }
        else {
            id = employees[employeesSize - 1].getId() + 2;
        }
        return id;
    }
    static void saveEmployee(Employee employee) {
        EmployeeFileManager e;
        vector<Employee> employees = e.getAllEmployees();
        int employeesSize = employees.size();
        int index = HelperMethods::idBinarySearch<Employee>(employees, employeesSize - 1, 0, employee.getId());
        employees[index].setName(employee.getName());
        employees[index].setPassword(employee.getPassword());
        employees[index].setSalary(employee.getSalary());
        ofstream writeFile("Employees.txt");
        for (int i = 0; i < employeesSize; i++) {
            if (i == (employeesSize - 1)) {
                writeFile << employees[i].getId() << ",";
                writeFile << employees[i].getName() << ",";
                writeFile << employees[i].getPassword() << ",";
                writeFile << employees[i].getSalary();
            }
            else {
                writeFile << employees[i].getId() << ",";
                writeFile << employees[i].getName() << ",";
                writeFile << employees[i].getPassword() << ",";
                writeFile << employees[i].getSalary() << endl;
            }
        }
        writeFile.close();
        return;
    }
    static void getEmployees() {
        EmployeeFileManager e;
        vector<Employee> employees = e.getAllEmployees();
        int employeesSize = employees.size();
        if (!employeesSize) {
            cout << "\n\nNo employees found !\n\n";
        }
        for (int i = 0; i < employeesSize; i++) {
            employees[i].display();
        }
    }
    static void clearFile() {
        EmployeeFileManager e;
        e.removeAllEmployees();
    }

};

