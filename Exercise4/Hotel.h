//
// Created by Oscar on 23/05/2017.
//

#ifndef TPCUATRIMESTRAL_HOTEL_H
#define TPCUATRIMESTRAL_HOTEL_H

#include "Room.h"
#include "Invoice.h"
#include "Client.h"
typedef struct hotel Hotel;
struct hotel{
    char* name;
    int ninHotel;
    Room** roomsArray;
    Invoice** invoiceArray;
    int roomsQuantity;
    int invoiceQuantity;
    int invoiceMaxCapacity;
    int invoiceCode;
    int roomsMaxCapacity;
};

Hotel* newHotel(char* name, int ninHotel, int roomsMaxCapacity);
void freeHotel(Hotel* hotel);
void addRoom(Hotel* hotel,Room* room);
void addInvoice(Hotel* hotel,Invoice* invoice);
Room* getRoom(Hotel* hotel, int roomNumber);
int getInvoiceCode(Hotel* hotel);
Invoice* payRoom(Client* client, Receptionist* receptionist, Hotel* hotel);
#endif //TPCUATRIMESTRAL_HOTEL_H
