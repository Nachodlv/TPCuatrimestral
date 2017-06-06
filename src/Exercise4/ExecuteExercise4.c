//
// Created by Gonzalo de Achaval on 31/5/17.
//


#include <stdio.h>
#include <stdlib.h>
#include "ExecuteExercise4.h"


int executeExercise4(){
    Client* client1 = newClientExercise4("Nacho", 40693681);
    Client* client2 = newClientExercise4("Gonza", 41222861);
    Client* client3 = newClientExercise4("Nanza", 12345678);
    int amountOfClients = 3;
    Client** clients = malloc(sizeof(Client*)*amountOfClients);
    clients[0] = client1;
    clients[1] = client2;
    clients[2] = client3;

    Room* suite1 = newRoom(1, 100, "Suite");
    Room* suite2 = newRoom(2, 100, "Suite");
    Room* regular1 = newRoom(3, 50, "Regular");
    Room* presidential = newRoom(4, 500, "Presidential");

    Hotel* hotel = newHotel("Samoa", 123, 6);
    addRoom(hotel, suite1);
    addRoom(hotel, suite2);
    addRoom(hotel, regular1);
    addRoom(hotel, presidential);

    Receptionist* receptionist = newReceptionist("Jimena", 30123654);

    printClients(clients, amountOfClients);
    Client* chosenClient = clients[getIndexExercise4()-1];
    actions(chosenClient, hotel, receptionist);

    return 0;
}


void printClients(Client **clients, int amountOfClients) {
    printf("%s", "Clients:");
    printf("\n");
    for(int i=0; i<amountOfClients; i++){
        printf(" %d\t", i+1);
        printf("%s\n", clients[i]->name);
    }
}

int getIndexExercise4() {
    int index;
    printf("%s", "Choose valid option: \t");
    scanf(" %i*c",&index);
    printf("\n");
    return index;
}

int getDays() {
    int index;
    printf("%s", "Enter amount of days of stay: \t");
    scanf(" %i*c",&index);
    printf("\n");
    return index;
}

void printOptions() {
    printf("\n");
    printf("%s\n", "1. Make reservation");
    printf("%s\n", "2. Check-in");
    printf("%s\n", "3. Pay Room");
    printf("%s\n", "4. Exit");
}

void actions(Client* chosenClient, Hotel* hotel, Receptionist* receptionist) {
    int trueFalse = 1;
    while(trueFalse){
        printOptions();
        int i = getIndexExercise4();

        switch(i){
            case 1:
                reservationMenu(hotel, chosenClient, receptionist);
                break;
            case 2:
                checkInMenu(hotel, chosenClient, receptionist);
                break;
            case 3:
                payRoomMenu(hotel, chosenClient, receptionist);
                break;
            case 4:
                trueFalse = 0;
                break;
            default: break;
        }
    }
}


void reservationMenu(Hotel* hotel, Client* client, Receptionist* receptionist) {
    for(int i=0; i<hotel->roomsQuantity; i++){
        if(hotel->roomsArray[i]->available == 1) {
            printf("%d", i+1);
            printf("%s%s\n", ". Room type: ", hotel->roomsArray[i]->roomType);
            printf("%s%d\n", "Room number: ", hotel->roomsArray[i]->roomNumber);
            printf("%s%.2f\n", "Price per day: ", hotel->roomsArray[i]->pricePerDay);
            printf("\n");
        }
    }
    Room* chosenRoom = hotel->roomsArray[getIndexExercise4()-1];
    int daysToStay = getDays();
    makeReservation(client, chosenRoom->roomNumber, receptionist, daysToStay);
}

void checkInMenu(Hotel* hotel, Client* client, Receptionist* receptionist) {
    if(checkIn(client, receptionist, hotel) == 0){
        printf("%s", "Reservation not found\n");
    }else{
        printf("%s%s%s", "WELCOME to ", hotel->name, ", hope you have a nice stay\n");
    }
}

void payRoomMenu(Hotel* hotel, Client* client, Receptionist* receptionist) {
    Invoice* invoice = payRoom(client, receptionist, hotel);
    if(invoice == NULL){
        printf("%s", "Operation cannot be completed. Please check-in.\n");
    }else{
        printInvoice(invoice, hotel);
    }
}

void printInvoice(Invoice* invoice, Hotel* hotel) {
    printf("\n");
    printf("%s%d\n", "Invoice number: ", getInvoiceCode(hotel));
    printf("%s%s\n", "Client name: ", invoice->clientName);
    printf("%s%d\n", "Client DNI: ", invoice->clientDni);
    printf("%s%.2f\n", "To pay: ", invoice->price);
}