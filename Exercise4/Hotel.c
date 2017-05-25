//
// Created by Oscar on 23/05/2017.
//

#include "Hotel.h"

Hotel* newHotel(char* name, int ninHotel, int roomsMaxCapacity){
    Hotel* hotel = malloc(sizeof(Hotel));
    hotel->invoiceArray = malloc(sizeof(Invoice*)*10);
    hotel->roomsArray = malloc(sizeof(Room*)*10);
    hotel->name = malloc(sizeof(char)*(strlen(name)+1));
    hotel->invoiceMaxCapacity = 10;
    hotel->roomsQuantity = 0;
    hotel->roomsMaxCapacity = roomsMaxCapacity;
    hotel->ninHotel = ninHotel;
    strcpy(hotel->name, name);
    hotel->invoiceCode = 0;
    hotel->invoiceQuantity = 0;
    return hotel;
}

void freeHotel(Hotel* hotel){
    for(int i=0; i<hotel->roomsQuantity; i++){
        free(hotel->roomsArray[i]);
    }
    for(int i=0; i<hotel->invoiceQuantity; i++){
        free(hotel->invoiceArray[i]);
    }
    free(hotel->name);
    free(hotel);
}

void addRoom(Hotel* hotel, Room* room){
    if(hotel->roomsQuantity == hotel->roomsMaxCapacity) {
        growRoomsArray();
    }
    hotel->roomsArray[hotel->roomsQuantity] = room;
    hotel->roomsQuantity = hotel->roomsQuantity+1;
}


void addInvoice(Hotel* hotel, Invoice* invoice){
    if(hotel->invoiceQuantity == hotel->invoiceMaxCapacity) {
        growInvoiceArray();
    }
    hotel->roomsInvoice[hotel->roomsInvoice] = room;
    hotel->invoiceQuantity = hotel->invoiceQuantity+1;
}

Room* getRoom(Hotel* hotel, int roomNumber){
    for(int i=0; i<hotel->roomsQuantity; i++){
        if(hotel->roomsArray[i]->roomNumber==roomNumber) return hotel->roomsArray[i];
    }
    exit(2);
}

void growRoomsArray(Hotel* hotel){
    hotel->roomsArray = realloc(hotel->roomsArray, sizeof(Room*)*hotel->roomsMaxCapacity*2);
    hotel->roomsMaxCapacity = hotel->roomsMaxCapacity*2;
}

void growInvoiceArray(Hotel* hotel){
    hotel->invoiceArray = realloc(hotel->invoiceArray, sizeof(Invoice*)*hotel->invoiceMaxCapacity*2);
    hotel->invoiceMaxCapacity = hotel->invoiceMaxCapacity*2;
}

int getInvoiceCode(Hotel* hotel) {
    int code = hotel->invoiceCode;
    hotel->invoiceCode = hotel->invoiceCode+1;
    return code;
}


