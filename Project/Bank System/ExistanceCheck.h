#pragma once
#include "ClientFileManager.h"
#include "EmployeeFileManager.h"
#include "AdminFileManager.h"
#include "HelperMethods.h"

class ExistanceCheck
{
public:

    //Methods:
    static int idExists(int id, string type) {
        if (type == "client") {
            ClientFileManager c;
            vector<Client> clients = c.getAllClients();
            int clientsSize = clients.size();
            return HelperMethods::idBinarySearch<Client>(clients, clientsSize - 1, 0, id);
        }
        else if (type == "employee") {
            EmployeeFileManager e;
            vector<Employee> employees = e.getAllEmployees();
            int employeesSize = employees.size();
            return HelperMethods::idBinarySearch<Employee>(employees, employeesSize - 1, 0, id);
        }
        else if (type == "admin") {
            AdminFileManager a;
            vector<Admin> admins = a.getAllAdmins();
            int adminsSize = admins.size();
            return HelperMethods::idBinarySearch<Admin>(admins, adminsSize - 1, 0, id);
        }
        return -1;
    }
    static bool passExists(int index, string password, string type) {
        if (type == "client") {
            ClientFileManager c;
            vector<Client> clients = c.getAllClients();
            if (clients[index].getPassword() == password) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (type == "employee") {
            EmployeeFileManager e;
            vector<Employee> employees = e.getAllEmployees();
            if (employees[index].getPassword() == password) {
                return true;
            }
            else {
                return false;
            }
        }
        else if (type == "admin") {
            AdminFileManager a;
            vector<Admin> admins = a.getAllAdmins();
            if (admins[index].getPassword() == password) {
                return true;
            }
            else {
                return false;
            }
        }
        return false;
    }
};

