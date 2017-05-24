//
// Created by Oscar on 23/05/2017.
//

#include "Client.h"
#include <stdlib.h>
#include <memory.h>
Client* newClient(char* name,int dni){
    Client* client = malloc(sizeof(Client));
    client->name=malloc(sizeof(char)*(strlen(name)+1));
    client->dni=dni;
    strcpy(client->name,name);
    return client;
}
void freeClient(Client* client){
    free(client->name);
    free(client);
}