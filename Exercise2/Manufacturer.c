//
// Created by Gonzalo de Achaval on 18/5/17.
//
#include <stdlib.h>
#include <memory.h>
#include "Manufacturer.h"

Manufacturer* newAppliance(char* name, int code){
    Manufacturer* manufacturer = malloc(sizeof(Manufacturer));
    manufacturer->name = malloc(sizeof(name));
    manufacturer->code=code;
    strcpy(manufacturer->name,name);
    return manufacturer;
}

void freeManufacturer(Manufacturer* manufacturer1){
    free(manufacturer1->name);
    free(manufacturer1);
}

