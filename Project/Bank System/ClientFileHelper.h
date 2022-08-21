#pragma once
#include "ClientFileManager.h"
#include "HelperMethods.h"

class ClientFileHelper
{
public:

    //Methods:
    static int getLastId() {
        ClientFileManager c;
        vector<Client> clients = c.getAllClients();
        int clientsSize = clients.size(), id;
        if (!clientsSize) {
            id = 2;
        }
        else {
            id = clients[clientsSize - 1].getId() + 2;
        }
        return id;
    }
    static void saveClient(Client client) {
        ClientFileManager c;
        vector<Client> clients = c.getAllClients();
        int clientsSize = clients.size();
        int index = HelperMethods::idBinarySearch<Client>(clients, clientsSize - 1, 0, client.getId());
        clients[index].setName(client.getName());
        clients[index].setPassword(client.getPassword());
        clients[index].setBalance(client.getBalance());
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
        return;
    }
    static void getClients() {
        ClientFileManager c;
        vector<Client> clients = c.getAllClients();
        int clientsSize = clients.size();
        if (!clientsSize) {
            cout << "\n\nNo clients found !\n\n";
        }
        for (int i = 0; i < clientsSize; i++) {
            clients[i].display();
        }
    }
    static void clearFile() {
        ClientFileManager c;
        c.removeAllClients();
    }


};


