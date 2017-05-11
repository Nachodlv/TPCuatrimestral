//
// Created by Ignacio on 10/5/2017.
//

#ifndef TPCUATRIMESTRAL_CART_H
#define TPCUATRIMESTRAL_CART_H

#include "LineCart.h"
#include "Appliance.h"
#include "Invoice.h"

typedef struct cart Cart;
struct cart{
    char* id;
    double total;
    LineCart** lineCartArray;
    int* lineCartBooleanArray;
};

Cart* newCart(char* id);
void freeCart(Cart* cart1);
void addAppliance(Cart* cart1,Appliance* appliance1);
Appliance* erraseAppliance(Cart* cart1,Appliance* appliance1);
Invoice* finishShopping(Cart* cart);
void grow(Cart* cart1);
#endif //TPCUATRIMESTRAL_CART_H
