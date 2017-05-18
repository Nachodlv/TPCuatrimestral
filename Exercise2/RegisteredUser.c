//
// Created by Gonzalo de Achaval on 18/5/17.
//

#include "RegisteredUser.h"
#include <stdlib.h>
#include <memory.h>
RegisteredUser* newResgisteredUser(char* name, char* dni, char* address, char* phone, char* location, char* province, char* country, char* postalCode){
    RegisteredUser* registeredUser1 = malloc(sizeof(RegisteredUser));
    registeredUser1->dni = malloc(sizeof(dni));
    registeredUser1->name = malloc(sizeof(name));
    registeredUser1->phone = malloc(sizeof(phone));
    registeredUser1->address = malloc(sizeof(address));
    registeredUser1->location = malloc(sizeof(location));
    registeredUser1->province = malloc(sizeof(province));
    registeredUser1->country = malloc(sizeof(country));
    registeredUser1->postalCode = malloc(sizeof(postalCode));
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
