//
// Created by Ignacio on 10/5/2017.
//


#include <stdlib.h>
#include <memory.h>
#include "Manufacturer.h"
#include "Provider.h"

Manufacturer* newManufacturer(char* name, char* description, char* direction, char*city, char* phone, char* web){
    Manufacturer* manufacturer = malloc(sizeof(manufacturer));
    manufacturer->createdAppliances=0;
    manufacturer->city=malloc(sizeof(city));
    manufacturer->name=malloc(sizeof(name));
    manufacturer->description=malloc(sizeof(description));
    manufacturer->direction=malloc(sizeof(direction));
    manufacturer->phone=malloc(sizeof(phone));
    manufacturer->web=malloc(sizeof(web));

    strcpy(manufacturer->city,city);
    strcpy(manufacturer->name,name);
    strcpy(manufacturer->description,description);
    strcpy(manufacturer->direction,direction);
    strcpy(manufacturer->phone,phone);
    strcpy(manufacturer->web,web);
    return manufacturer;
}

void freeManufacturer(Manufacturer* manufacturer){
    free(manufacturer->city);
    free(manufacturer->name);
    free(manufacturer->description);
    free(manufacturer->direction);
    free(manufacturer->phone);
    free(manufacturer->web);
    free(manufacturer);
}

void createAppliance(Manufacturer* manufacturer1, Provider* provider1, int quantity){
    manufacturer1->createdAppliances+=quantity;
    provider1->appliancesQuantity+=quantity;
}
