//
// Created by Oscar on 23/05/2017.
//

#include "Room.h"
Room* newRoom(int roomNumber, double pricePerDay,char* roomType){
    Room* room = malloc(sizeof(Room));
    room->roomNumber=roomNumber;
    room->pricePerDay=pricePerDay;
    room->roomType=malloc(sizeof(char)*(strlen(roomType)+1));
    room->available=1;
    strcpy(room->roomType,roomType);
    return room;
}