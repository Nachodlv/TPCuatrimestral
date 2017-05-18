//
// Created by Gonzalo de Achaval on 18/5/17.
//

#ifndef TPCUATRIMESTRAL_PRODUCT_H
#define TPCUATRIMESTRAL_PRODUCT_H
#include "Manufacturer.h"
#include "Provider.h"

typedef struct product Product;
struct product{
    char* name;
    char* code;
    double price;
    char* photo;
    Provider* provider1;
    Manufacturer* manufacturer1;
};
Product* newProduct(char* name, char* code, double price, char* photo, Provider* provider1, Manufacturer* manufacturer1);
void freeProduct(Product* product1);

#endif //TPCUATRIMESTRAL_PRODUCT_H
