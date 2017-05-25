//
// Created by Oscar on 23/05/2017.
//

#include "Reservation.h"
#include <stdlib.h>
#include <memory.h>

Reservation* newReservation(Client* client, int roomNumber, int daysToStay){
    Reservation* reservation = malloc(sizeof(Reservation));
    reservation->clientName=malloc(sizeof(char)*(strlen(client->name)+1));
    reservation->daysToStay=daysToStay;
    reservation->dni=client->dni;
    reservation->roomNumber=roomNumber;
    strcpy(reservation->clientName,client->name);
    return reservation;
}

void freeReservation(Reservation* reservation){
    free(reservation->clientName);
    free(reservation);
}