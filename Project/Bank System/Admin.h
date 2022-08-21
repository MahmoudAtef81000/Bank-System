#pragma once

#include "Employee.h"
#include "EmployeeFileHelper.h"

class Admin : public Employee
{
public:

    //Constructors:
    Admin() {

    }
    Admin(int id, string name, string password,
        double salary) :Employee(id, name, password, salary) {
    }

    //Methods:
    void addEmployee(Employee employee) {
        EmployeeFileManager e;
        e.addEmployee(employee);
    }
    Employee searchEmployee(int id) {
        EmployeeFileManager e;
        vector<Employee> employees = e.getAllEmployees();
        int employeesSize = employees.size();
        int index = HelperMethods::idBinarySearch(employees, employeesSize - 1, 0, id);
        return employees[index];
    }
    void editEmployee(int id, string name, string password,
        double salary) {
        Employee employee(id, name, password, salary);
        EmployeeFileHelper::saveEmployee(employee);
    }
    void removeEmployee(int id) {
        EmployeeFileManager e;
        e.removeEmployee(id);
    }
    void listAllEmployees() {
        EmployeeFileHelper::getEmployees();
    }
    void listEmployee(int id) {
        Employee employee = searchEmployee(id);
        employee.display();
    }
    void display() {
        cout << "Admin Info:\n-----------\n";
        Person::display();
        cout << "Salary: " << salary << endl;
        cout << "================================\n";
    }

    //Destructor:
    ~Admin() {

    }

};

