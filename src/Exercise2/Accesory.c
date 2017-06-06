//
// Created by Gonzalo de Achaval on 18/5/17.
//
#include <stdlib.h>
#include <memory.h>
#include "Accesory.h"

Accesory* newAccesory(int accesoryType, char* comment, int code){
    Accesory* accesory = malloc(sizeof(Accesory));
    accesory->comment = malloc(sizeof(char)*(strlen(comment)+1));
    accesory->accesoryType=accesoryType;
    accesory->code=code;
    strcpy(accesory->comment,comment);
    return accesory;
}

void freeAccesory(Accesory* accesory){
    free(accesory->comment);
    free(accesory);
}