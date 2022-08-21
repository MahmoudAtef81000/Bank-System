#pragma once
#include "Client.h"
#include "ClientFileHelper.h"
#include "HelperMethods.h"


class Employee : public Person
{
protected:

    //Attributes:
    double salary;

public:

    //Constructors:
    Employee() {
        salary = 0;
    }
    Employee(int id, string name, string password,
        double salary) :Person(id, name, password) {
        this->salary = salary;
    }

    //Setters:
    void setSalary(double salary) {
        this->salary = salary;
    }

    //Getters:
    double getSalary() {
        return salary;
    }

    //Methods:
    void addClient(Client client) {
        ClientFileManager c;
        c.addClient(client);
    }
    Client searchClient(int id) {
        ClientFileManager c;
        vector<Client> clients = c.getAllClients();
        int clientsSize = clients.size();
        int index = HelperMethods::idBinarySearch(clients, clientsSize - 1, 0, id);
        return clients[index];
    }
    void editClient(int id, string name, string password,
        double balance) {
        Client client = searchClient(id);
        client.setName(name);
        client.setPassword(password);
        client.setBalance(balance);
        ClientFileHelper::saveClient(client);
    }
    void removeClient(int id) {
        ClientFileManager c;
        c.removeClient(id);
    }
    void listAllClients() {
        ClientFileHelper::getClients();
    }
    void listClient(int id) {
        Client client = searchClient(id);
        client.display();
    }
    void display() {
        cout << "Employee Info:\n--------------\n";
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "================================\n";
    }

    //Destructor:
    ~Employee() {

    }

};

