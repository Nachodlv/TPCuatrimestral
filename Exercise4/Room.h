//
// Created by Oscar on 23/05/2017.
//

#ifndef TPCUATRIMESTRAL_ROOM_H
#define TPCUATRIMESTRAL_ROOM_H
typedef struct room Room;
struct room{
    int roomNumber;
    double pricePerDay;
    char* roomType;
    int available;
};
Room* newRoom(int roomNumber, double pricePerDay,char* roomType);
void freeRoom(Room* room);
#endif //TPCUATRIMESTRAL_ROOM_H
