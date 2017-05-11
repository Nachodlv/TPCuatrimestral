//
// Created by Ignacio on 10/5/2017.
//

#include <malloc.h>
#include <mem.h>
#include "Manufacturer.h"

Manufacturer* newManufacturer(char* name, char* description, char* direction, char*city, char* phone, char* web){
    Manufacturer* manufacturer = malloc(sizeof(manufacturer));
    manufacturer->createdAppliances=0;
    manufacturer->city=malloc(sizeof(strlen(city)));
    manufacturer->name=malloc(sizeof(strlen(name)));
    manufacturer->description=malloc(sizeof(strlen(description)));
    manufacturer->direction=malloc(sizeof(strlen(direction)));
    manufacturer->phone=malloc(sizeof(strlen(phone)));
    manufacturer->web=malloc(sizeof(strlen(web)));

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
