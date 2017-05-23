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
Client* newClient(char* name,int dni);
void freeClient(Client* client);
void makeReservation(Client* client, int roomNumber);
#endif //TPCUATRIMESTRAL_CLIENT_H
