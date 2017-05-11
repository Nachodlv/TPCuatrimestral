//
// Created by Ignacio on 10/5/2017.
//

#ifndef TPCUATRIMESTRAL_CATALOGUE_H
#define TPCUATRIMESTRAL_CATALOGUE_H

#include "Appliance.h"
typedef struct catalogue Catalogue;
struct catalogue{
    char* id;
    char* name;
    double discount;
    Appliance** applianceArray;
    int* applianceBooleanArray;
};

Catalogue* newCatalogue(char* id,char* name, double discount);
void freeCatalogue(Catalogue* catalogue1);
void addAppliance(Catalogue* catalogue1,Appliance* appliance1);
Appliance* removeAppliance(Catalogue* catalogue1, Appliance* appliance1);
void grow(Catalogue* catalogue1);
#endif //TPCUATRIMESTRAL_CATALOGUE_H
