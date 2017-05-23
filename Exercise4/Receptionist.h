//
// Created by Oscar on 23/05/2017.
//

#ifndef TPCUATRIMESTRAL_RECEPTIONIST_H
#define TPCUATRIMESTRAL_RECEPTIONIST_H

#include "Client.h"
typedef struct receptionist Receptionist;
struct receptionist{
    Reservation** reservationArray;
    int* reservationBooleanQuantity;
    int currentReservationQuantity;
    int reservationMaxCapacity;
    char* name;
    int dni;
};
Receptionist* newReceptionist(char* name,int dni, Hotel* hotel);

#endif //TPCUATRIMESTRAL_RECEPTIONIST_H
