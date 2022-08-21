#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "EmployeeDataInterface.h"



class EmployeeFileManager : public EmployeeDataInterface
{
public:

    //Methods:
    vector<Employee>getAllEmployees() {
        vector<Employee> employees;
        ifstream readFile("Employees.txt");
        string lineData;
        while (getline(readFile, lineData)) {
            employees.push_back(Parser::parseToEmployee<Employee>(lineData));
        }
        readFile.close();
        return employees;
    }
    void addEmployee(Employee employee) {
        ofstream writeFile("Employees.txt", ios::app);
        writeFile << endl << employee.getId() << ",";
        writeFile << employee.getName() << ",";
        writeFile << employee.getPassword() << ",";
        writeFile << employee.getSalary();
        writeFile.close();
    }
    void removeEmployee(int id) {
        vector<Employee> employees = getAllEmployees();
        int employeesSize = employees.size();
        int index = HelperMethods::idBinarySearch<Employee>(employees, employeesSize - 1, 0, id);
        employees.erase(employees.begin() + index);
        employeesSize--;
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
    }
    void removeAllEmployees() {
        ofstream writeFile("Employees.txt");
        writeFile << "";
        writeFile.close();
    }

};

