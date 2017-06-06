//
// Created by Oscar on 23/05/2017.
//

#ifndef TPCUATRIMESTRAL_CLIENT_H
#define TPCUATRIMESTRAL_CLIENT_H
typedef struct client Client;
struct client{
    char* name;
    int dni;
};
Client* newClientExercise4(char *name, int dni);
void freeClientExercise4(Client* client);

#endif //TPCUATRIMESTRAL_CLIENT_H
