//
// Created by Oscar on 23/05/2017.
//

#include <stdlib.h>
#include <memory.h>
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
        growRoomsArray(hotel);
    }
    hotel->roomsArray[hotel->roomsQuantity] = room;
    hotel->roomsQuantity = hotel->roomsQuantity+1;
}


void addInvoice(Hotel* hotel, Invoice* invoice){
    if(hotel->invoiceQuantity == hotel->invoiceMaxCapacity) {
        growInvoiceArray(hotel);
    }
    hotel->invoiceArray[hotel->invoiceQuantity] = invoice;
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

Invoice* payRoom(Client* client, Receptionist* receptionist, Hotel* hotel){
    Reservation* reservation = getReservation(client->dni,receptionist);
    Room* room = getRoom(hotel,reservation->roomNumber);
    room->available=1;
    deleteReservation(client->dni,receptionist);
    Invoice* invoice = newInvoiceExercise4(getInvoiceCode(hotel),hotel->ninHotel,hotel->name,client->name,client->dni,room->pricePerDay*reservation->daysToStay);
    addInvoice(hotel,invoice);
    return invoice;
}
int checkIn(Client* client, Receptionist* receptionist, Hotel* hotel){
    int roomNumber=-1;
    for(int i=0;i<receptionist->reservationMaxCapacity;i++){
        if(receptionist->reservationBooleanArray[i]==1){
            if(receptionist->reservationArray[i]->dni==client->dni){
                roomNumber=receptionist->reservationArray[i]->roomNumber;
            }
        }
    }
    if(roomNumber==-1) return 0;
    getRoom(hotel,roomNumber)->available=0;
    return 1;
}

