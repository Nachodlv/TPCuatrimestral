//
// Created by Ignacio on 10/5/2017.
//


#include <stdlib.h>
#include <memory.h>
#include "Provider.h"
#include "Appliance.h"

Provider* newProvider(char* name, char* description, char* direction, char*city, char* phone, char* web, Manufacturer* manufacturer){
    Provider* provider = malloc(sizeof(provider));
    provider->appliancesQuantity=0;
    provider->city=malloc(sizeof(city));
    provider->name=malloc(sizeof(name));
    provider->description=malloc(sizeof(description));
    provider->direction=malloc(sizeof(direction));
    provider->phone=malloc(sizeof(phone));
    provider->web=malloc(sizeof(web));
    provider->manufacturer=manufacturer;

    strcpy(provider->city,city);
    strcpy(provider->name,name);
    strcpy(provider->description,description);
    strcpy(provider->direction,direction);
    strcpy(provider->phone,phone);
    strcpy(provider->web,web);
    return provider;
}

void freeProvider(Provider* provider){
    free(provider->city);
    free(provider->name);
    free(provider->description);
    free(provider->direction);
    free(provider->phone);
    free(provider->web);
    freeManufacturer(provider->manufacturer);
    free(provider->manufacturer);
    free(provider);
}

void askForAppliance(Provider* provider1,LineCart* lineCart1){
    if(provider1->appliancesQuantity==0){
        createAppliance(provider1->manufacturer,provider1,15);
    }
    provider1->appliancesQuantity-=5;
    lineCart1->quantity+=10;
}