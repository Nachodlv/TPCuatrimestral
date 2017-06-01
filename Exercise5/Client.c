//
// Created by Ignacio on 30/5/2017.
//

#include "Client.h"
#include <stdlib.h>
#include <memory.h>

Client* newClient(char* name, int numberId){
    Client* client = malloc(sizeof(Client));
    client->name=malloc(sizeof(char)*strlen(name));
    client->id=malloc(sizeof(Id));
    client->id=newId(numberId);
    strcpy(client->name,name);
    return client;
}

void freeClient(Client* client){
    free(client->name);
    freeId(client->id);
    free(client);
}