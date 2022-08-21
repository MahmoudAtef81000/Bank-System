#pragma once
#include "Validation.h"


using namespace std;

class Person
{
protected:

    //Attributes:
    int id;
    string name;
    string password;

public:

    //Constructors:
    Person() {
        id = 0;
        name = " ";
        password = " ";
    }
    Person(int id, string name, string password) {
        this->id = id;
        this->name = name;
        this->password = password;
    }

    //Setters:
    void setId(int id) {
        this->id = id;
    }
    void setName(string name) {
        this->name = name;
    }
    void setPassword(string password) {
        this->password = password;
    }

    //Getters:
    int getId() {
        return id;
    }
    string getName() {
        return name;
    }
    string getPassword() {
        return password;
    }

    //Methods:
    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    };

    //Destructor:
    ~Person() {

    }
};

