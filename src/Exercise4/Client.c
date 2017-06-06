//
// Created by Oscar on 23/05/2017.
//

#include "Client.h"
#include <stdlib.h>
#include <memory.h>
Client* newClientExercise4(char* name,int dni){
    Client* client = malloc(sizeof(Client));
    client->name=malloc(sizeof(char)*(strlen(name)+1));
    client->dni=dni;
    strcpy(client->name,name);
    return client;
}
void freeClientExercise4(Client* client){
    free(client->name);
    free(client);
}