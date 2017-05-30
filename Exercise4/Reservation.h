//
// Created by Oscar on 23/05/2017.
//

#ifndef TPCUATRIMESTRAL_RESERVATION_H
#define TPCUATRIMESTRAL_RESERVATION_H

#include "Client.h"
typedef struct reservation Reservation;
struct reservation{
    char* clientName;
    int dni;
    int roomNumber;
    int daysToStay;
};
Reservation* newReservation(Client* client, int roomNumber, int daysToStay);
void freeReservation(Reservation* reservation);
#endif //TPCUATRIMESTRAL_RESERVATION_H
