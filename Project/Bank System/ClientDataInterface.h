#pragma once
#include <vector>
#include "Client.h"

class ClientDataInterface
{
public:

    //Methods:
    virtual void addClient(Client client) = 0;
    virtual vector<Client> getAllClients() = 0;
    virtual void removeClient(int id) = 0;
    virtual void removeAllClients() = 0;

};

