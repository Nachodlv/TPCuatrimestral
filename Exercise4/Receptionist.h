//
// Created by Oscar on 23/05/2017.
//

#ifndef TPCUATRIMESTRAL_RECEPTIONIST_H
#define TPCUATRIMESTRAL_RECEPTIONIST_H

#include "Client.h"
#include "Hotel.h"
#include "Reservation.h"
typedef struct receptionist Receptionist;
struct receptionist{
    Reservation** reservationArray;
    int* reservationBooleanArray;
    int currentReservationQuantity;
    int reservationMaxCapacity;
    char* name;
    int dni;
};
Receptionist* newReceptionist(char* name,int dni);
void freeReceptionist(Receptionist* receptionist);
int checkIn(Client* client, Receptionist* receptionist, Hotel* hotel);
void makeReservation(Client* client, int roomNumber, Receptionist* receptionist,int daysToStay);
Reservation* getReservation(int clientDni, Receptionist* receptionist);
void deleteReservation(int clientDni,Receptionist* receptionist);
void growReservationArray(Receptionist* receptionist);
#endif //TPCUATRIMESTRAL_RECEPTIONIST_H
