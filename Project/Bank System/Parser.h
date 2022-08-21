#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Parser
{
public:

    //Methods:
    template <class Type>
    static Type parseToClient(string line) {
        Type type; 
        string id, name, password, balance;
        stringstream in(line);
        getline(in, id, ',');
        getline(in, name, ',');
        getline(in, password, ',');
        getline(in, balance, ',');
        type.setId(stoi(id));
        type.setName(name);
        type.setPassword(password);
        type.setBalance(stod(balance));
        return type;
    }
    template <class Type>
    static Type parseToEmployee(string line) {
        Type type;
        string id, name, password, salary;
        stringstream in(line);
        getline(in, id, ',');
        getline(in, name, ',');
        getline(in, password, ',');
        getline(in, salary, ',');
        type.setId(stoi(id));
        type.setName(name);
        type.setPassword(password);
        type.setSalary(stod(salary));
        return type;
    }
    
};

