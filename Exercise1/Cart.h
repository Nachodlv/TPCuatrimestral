//
// Created by Ignacio on 10/5/2017.
//

#ifndef TPCUATRIMESTRAL_CART_H
#define TPCUATRIMESTRAL_CART_H

typedef struct lineCart LineCart;
typedef struct appliance Appliance;
typedef struct invoice Invoice;
typedef struct cart Cart;
struct cart{
    char* id;
    double total;
    LineCart** lineCartArray;
    int* lineCartBooleanArray;
    int maxCapacity;
};

Cart* newCart(char* id);
void freeCart(Cart* cart1);
void addToCart(Cart* cart1,Appliance* appliance1);
Appliance* erraseAppliance(Cart* cart1,Appliance* appliance1);
Invoice* finishShopping(Cart* cart);
void growCart(Cart* cart1);
#endif //TPCUATRIMESTRAL_CART_H
