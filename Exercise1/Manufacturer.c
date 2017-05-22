//
// Created by Ignacio on 10/5/2017.
//


#include <stdlib.h>
#include <memory.h>
#include "Manufacturer.h"
#include "Provider.h"

Manufacturer* newManufacturer(char* name, char* description, char* direction, char*city, char* phone, char* web){
    Manufacturer* manufacturer = malloc(sizeof(Manufacturer));
    manufacturer->createdAppliances=0;
    manufacturer->city=malloc(sizeof(char)*(strlen(city)+1));
    manufacturer->name=malloc(sizeof(char)*(strlen(name)+1));
    manufacturer->description=malloc(sizeof(char)*(strlen(description)+1));
    manufacturer->direction=malloc(sizeof(char)*(strlen(direction)+1));
    manufacturer->phone=malloc(sizeof(char)*(strlen(phone)+1));
    manufacturer->web=malloc(sizeof(char)*(strlen(web)+1));

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
