//
// Created by Gonzalo de Achaval on 18/5/17.
//
#include <stdlib.h>
#include <memory.h>
#include "Manufacturer.h"

Manufacturer* newManufacturerExercise2(char* name, int code){
    Manufacturer* manufacturer = malloc(sizeof(Manufacturer));
    manufacturer->name = malloc(sizeof(char)*(strlen(name)+1));
    manufacturer->code=code;
    strcpy(manufacturer->name,name);
    return manufacturer;
}

void freeManufacturerExercise2(Manufacturer* manufacturer1){
    free(manufacturer1->name);
    free(manufacturer1);
}

