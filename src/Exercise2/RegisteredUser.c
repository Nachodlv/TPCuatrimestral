//
// Created by Gonzalo de Achaval on 18/5/17.
//

#include "RegisteredUser.h"
#include <stdlib.h>
#include <memory.h>
RegisteredUser* newResgisteredUser(char* name, char* dni, char* address, char* phone, char* location, char* province, char* country, char* postalCode){
    RegisteredUser* registeredUser1 = malloc(sizeof(RegisteredUser));
    registeredUser1->dni = malloc(sizeof(char)*(strlen(dni)+1));
    registeredUser1->name = malloc(sizeof(char)*(strlen(name)+1));
    registeredUser1->phone = malloc(sizeof(char)*(strlen(phone)+1));
    registeredUser1->address = malloc(sizeof(char)*(strlen(address)+1));
    registeredUser1->location = malloc(sizeof(char)*(strlen(location)+1));
    registeredUser1->province = malloc(sizeof(char)*(strlen(province)+1));
    registeredUser1->country = malloc(sizeof(char)*(strlen(country)+1));
    registeredUser1->postalCode = malloc(sizeof(char)*(strlen(postalCode)+1));
    strcpy(registeredUser1->dni,dni);
    strcpy(registeredUser1->name,name);
    strcpy(registeredUser1->phone,phone);
    strcpy(registeredUser1->address,address);
    strcpy(registeredUser1->location,location);
    strcpy(registeredUser1->province,province);
    strcpy(registeredUser1->country,country);
    strcpy(registeredUser1->postalCode,postalCode);
    return registeredUser1;
}

void freeResgisteredUser(RegisteredUser* registeredUser1){
    free(registeredUser1->name);
    free(registeredUser1->phone);
    free(registeredUser1->address);
    free(registeredUser1->location);
    free(registeredUser1->province);
    free(registeredUser1->country);
    free(registeredUser1->postalCode);
    free(registeredUser1->dni);
    free(registeredUser1);
}
