//
// Created by Ignacio on 10/5/2017.
//


#include <stdlib.h>
#include <memory.h>
#include "LineCart.h"
#include "Appliance.h"

LineCart* newLineCart(char* id, Appliance* appliance1){
    LineCart* lineCart1 = malloc(sizeof(LineCart));
    lineCart1->id=malloc(sizeof(id));
    lineCart1->appliance1 =malloc(sizeof(appliance1));
    lineCart1->quantity=1;

    strcpy(lineCart1->id,id);
    lineCart1->appliance1=appliance1;
    return lineCart1;
}



void freeLineCart(LineCart* lineCart1){
    freeAppliance(lineCart1->appliance1);
    free(lineCart1->id);
    free(lineCart1->appliance1);
    free(lineCart1);
}