//
// Created by Oscar on 23/05/2017.
//

#include "Receptionist.h"
#include <stdlib.h>
#include <memory.h>
Receptionist* newReceptionist(char* name,int dni){
    Receptionist* receptionist = malloc(sizeof(Receptionist));
    receptionist->name=malloc(sizeof(char)*(strlen(name)+1));
    receptionist->dni=dni;
    receptionist->currentReservationQuantity=0;
    receptionist->reservationArray=malloc(sizeof(Reservation*)*10);
    receptionist->reservationBooleanArray=malloc(sizeof(int)*10);
    receptionist->reservationMaxCapacity=10;
    strcpy(receptionist->name,name);
    for(int i=0;i<10;i++){
        receptionist->reservationBooleanArray[i]=0;
    }
    return receptionist;
}

void freeReceptionist(Receptionist* receptionist){
    free(receptionist->name);
    for(int i=0;i<receptionist->reservationMaxCapacity;i++){
        if(receptionist->reservationBooleanArray[i]==1) freeReservation(receptionist->reservationArray[i]);
    }
    free(receptionist->reservationArray);
    free(receptionist->reservationBooleanArray);
    free(receptionist);
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

void makeReservation(Client* client, int roomNumber, Receptionist* receptionist,int daysToStay){
    for(int i=0;i<receptionist->reservationMaxCapacity;i++){
        if(receptionist->reservationBooleanArray[i]==0){
            receptionist->reservationArray[i]=newReservation(client,roomNumber,daysToStay);
            receptionist->reservationBooleanArray[i]=1;
            return;
        }
    }
    growReservationArray(receptionist);
    makeReservation(client,roomNumber,receptionist,daysToStay);
}

void growReservationArray(Receptionist* receptionist){
    receptionist->reservationArray=realloc(receptionist->reservationArray, sizeof(Reservation*)*receptionist->reservationMaxCapacity*2);
    receptionist->reservationBooleanArray=realloc(receptionist->reservationBooleanArray, sizeof(int)*receptionist->reservationMaxCapacity*2);
    for(int i=receptionist->reservationMaxCapacity;i<receptionist->reservationMaxCapacity*2;i++){
        receptionist->reservationBooleanArray[i]=0;
    }
    receptionist->reservationMaxCapacity=receptionist->reservationMaxCapacity*2;
}

void deleteReservation(int clientDni,Receptionist* receptionist){
    for(int i=0;i<receptionist->reservationMaxCapacity;i++){
        if(receptionist->reservationBooleanArray[i]==1){
            if(receptionist->reservationArray[i]->dni==clientDni){
                freeReservation(receptionist->reservationArray[i]);
                receptionist->reservationBooleanArray[i]=0;
                return;
            }
        }
    }
}

Reservation* getReservation(int clientDni, Receptionist* receptionist){
    for(int i=0;i<receptionist->reservationMaxCapacity;i++){
        if(receptionist->reservationBooleanArray[i]==1){
            if(receptionist->reservationArray[i]->dni==clientDni) return receptionist->reservationArray[i];
        }
    }
    exit(2);
}