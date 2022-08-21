#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "ClientDataInterface.h"
#include "HelperMethods.h"
#include "Parser.h"

class ClientFileManager : public ClientDataInterface
{
public:

    //Methods:
    vector<Client> getAllClients() {
        vector<Client> clients;
        ifstream readFile("Clients.txt");
        string lineData;
        while (getline(readFile, lineData)) {
            clients.push_back(Parser::parseToClient<Client>(lineData));
        }
        readFile.close();
        return clients;
    }
    void addClient(Client client) {
        ofstream writeFile("Clients.txt", ios::app);
        writeFile << endl << client.getId() << ",";
        writeFile << client.getName() << ",";
        writeFile << client.getPassword() << ",";
        writeFile << client.getBalance();
        writeFile.close();
    }
    void removeClient(int id) {
        vector<Client> clients = getAllClients();
        int clientsSize = clients.size();
        int index = HelperMethods::idBinarySearch<Client>(clients, clientsSize - 1, 0, id);
        clients.erase(clients.begin() + index);
        clientsSize--;
        ofstream writeFile("Clients.txt");
        for (int i = 0; i < clientsSize; i++) {
            if (i == (clientsSize - 1)) {
                writeFile << clients[i].getId() << ",";
                writeFile << clients[i].getName() << ",";
                writeFile << clients[i].getPassword() << ",";
                writeFile << clients[i].getBalance();
            }
            else {
                writeFile << clients[i].getId() << ",";
                writeFile << clients[i].getName() << ",";
                writeFile << clients[i].getPassword() << ",";
                writeFile << clients[i].getBalance() << endl;
            }
        }
        writeFile.close();
    }
    void removeAllClients() {
        ofstream writeFile("Clients.txt");
        writeFile << "";
        writeFile.close();
    }

};

