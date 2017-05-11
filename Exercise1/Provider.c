//
// Created by Ignacio on 10/5/2017.
//


#include <stdlib.h>
#include <memory.h>
#include "Provider.h"
#include "Appliance.h"
#include "Manufacturer.h"
#include "InvoiceLine.h"

Provider* newProvider(char* name, char* description, char* direction, char*city, char* phone, char* web, Manufacturer* manufacturer){
    Provider* provider = malloc(sizeof(provider));
    provider->appliancesQuantity=0;
    provider->city=malloc(sizeof(city));
    provider->name=malloc(sizeof(name));
    provider->description=malloc(sizeof(description));
    provider->direction=malloc(sizeof(direction));
    provider->phone=malloc(sizeof(phone));
    provider->web=malloc(sizeof(web));
    provider->manufacturer=malloc(sizeof(manufacturer));
    setSpaceForProvider(provider,manufacturer);

    strcpy(provider->city,city);
    strcpy(provider->name,name);
    strcpy(provider->description,description);
    strcpy(provider->direction,direction);
    strcpy(provider->phone,phone);
    strcpy(provider->web,web);
    return provider;
}

void setSpaceForProvider(Provider* provider1,Manufacturer* manufacturer1){
    provider1->manufacturer->city=malloc(sizeof(manufacturer1->city));
    provider1->manufacturer->name=malloc(sizeof(manufacturer1->name));
    provider1->manufacturer->description=malloc(sizeof(manufacturer1->description));
    provider1->manufacturer->direction=malloc(sizeof(manufacturer1->direction));
    provider1->manufacturer->phone=malloc(sizeof(manufacturer1->phone));
    provider1->manufacturer->web=malloc(sizeof(manufacturer1->web));
    strcpy(provider1->manufacturer->city,manufacturer1->city);
    strcpy(provider1->manufacturer->name,manufacturer1->name);
    strcpy(provider1->manufacturer->description,manufacturer1->description);
    strcpy(provider1->manufacturer->direction,manufacturer1->direction);
    strcpy(provider1->manufacturer->phone,manufacturer1->phone);
    strcpy(provider1->manufacturer->web,manufacturer1->web);
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

void askForAppliances(Provider* provider1,InvoiceLine* invoiceLine1){
    if(provider1->appliancesQuantity==0){
        createAppliance(provider1->manufacturer,provider1,15);
    }
    provider1->appliancesQuantity-=5;
    invoiceLine1->quantity+=10;
}