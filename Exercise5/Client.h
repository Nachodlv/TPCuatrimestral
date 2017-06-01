//
// Created by Ignacio on 30/5/2017.
//

#ifndef TPCUATRIMESTRAL_CLIENT_H
#define TPCUATRIMESTRAL_CLIENT_H

#include "Id.h"
#include "Movie.h"

typedef struct client Client;
struct client{
    char* name;
    Id* id;
};
Client* newClientExercise5(char* name, int numberId);
void freeClientExercise5(Client* client);
#endif //TPCUATRIMESTRAL_CLIENT_H
