//
// Created by Oscar on 23/05/2017.
//

#ifndef TPCUATRIMESTRAL_RESERVATION_H
#define TPCUATRIMESTRAL_RESERVATION_H
typedef struct reservation Reservation;
struct reservation{
    char* clientNumber;
    int dni;
    int roomNumber;
    int daysToStay;
};
Reservation* newReservation(Client* cliet, int roomNumber);
void freeReservation(Reservation* reservation);
#endif //TPCUATRIMESTRAL_RESERVATION_H
