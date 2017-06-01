//
// Created by Gonzalo de Achaval on 31/5/17.
//

#ifndef TPCUATRIMESTRAL_EXECUTEEXERCISE4_H
#define TPCUATRIMESTRAL_EXECUTEEXERCISE4_H

#include "Client.h"
#include "Hotel.h"

int executeExercise4();
void printClients(Client **clients, int amountOfClients);
int getIndex();
int getDays();
void printOptions();
void actions(Client* chosenClient, Hotel* hotel, Receptionist* receptionist);
void reservationMenu(Hotel* hotel, Client* client, Receptionist* receptionist);
void checkInMenu(Hotel* hotel, Client* client, Receptionist* receptionist);
void payRoomMenu(Hotel* hotel, Client* client, Receptionist* receptionist);
void printInvoice(Invoice* invoice);

#endif //TPCUATRIMESTRAL_EXECUTEEXERCISE4_H
