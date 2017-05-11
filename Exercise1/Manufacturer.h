

#ifndef TPCUATRIMESTRAL_MANUFACTURER_H
#define TPCUATRIMESTRAL_MANUFACTURER_H

#include "Provider.h"
typedef struct manufacturer Manufacturer;
struct manufacturer{
    char* name;
    char* description;
    char* direction;
    char* city;
    char* phone;
    char* web;
    int createdAppliances;
};
Manufacturer* newManufacturer(char* name, char* description, char* direction, char*city, char* phone, char* web);
void freeManufacturer(Manufacturer* manufacturer);
void createAppliance(Manufacturer* manufacturer1,Provider* provider1, int quantity);

#endif //TPCUATRIMESTRAL_MANUFACTURER_H
