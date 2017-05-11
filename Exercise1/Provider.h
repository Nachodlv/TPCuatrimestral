//
// Created by Ignacio on 10/5/2017.
//

#ifndef TPCUATRIMESTRAL_PROVIDER_H
#define TPCUATRIMESTRAL_PROVIDER_H

#include "Manufacturer.h"
#include "InvoiceLine.h"
#include "LineCart.h"

typedef struct provider Provider;
struct provider{
    char* name;
    char* description;
    char* direction;
    char* city;
    char* phone;
    char* web;
    Manufacturer* manufacturer;
    int appliancesQuantity;
};
Provider* newProvider(char* name, char* description, char* direction, char*city, char* phone, char* web, Manufacturer* manufacturer);
void freeProvider(Provider* provider);
void askForAppliances(Provider* provider1, LineCart* lineCart1);

#endif //TPCUATRIMESTRAL_PROVIDER_H
