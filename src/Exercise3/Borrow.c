//
// Created by Ignacio on 19/5/2017.
//

#include "Borrow.h"
#include <stdlib.h>
#include <memory.h>

Borrow* newBorrow(double price, int returnDays, char* materialName){
    Borrow* borrow = malloc(sizeof(Borrow));
    borrow->price=price;
    borrow->departureDate=time(0);
    borrow->returnDays=returnDays;
    borrow->materialName = malloc(sizeof(char)*(strlen(materialName)+1));
    strcpy(borrow->materialName,materialName);
    return borrow;
}

void freeBorrow(Borrow* borrow){
    free(borrow->materialName);
    free(borrow);
}
