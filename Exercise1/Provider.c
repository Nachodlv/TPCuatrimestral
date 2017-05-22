//
// Created by Ignacio on 10/5/2017.
//


#include <stdlib.h>
#include <memory.h>
#include "Provider.h"
#include "Appliance.h"
#include "Manufacturer.h"
#include "Stock.h"

Provider* newProvider(char* name, char* description, char* direction, char*city, char* phone, char* web, Manufacturer* manufacturer){
    Provider* provider = malloc(sizeof(Provider));
    provider->appliancesQuantity=0;
    provider->city=malloc(sizeof(char)*(strlen(city)+1));
    provider->name=malloc(sizeof(char)*(strlen(name)+1));
    provider->description=malloc(sizeof(char)*(strlen(description)+1));
    provider->direction=malloc(sizeof(char)*(strlen(direction)+1));
    provider->phone=malloc(sizeof(char)*(strlen(phone)+1));
    provider->web=malloc(sizeof(char)*(strlen(web)+1));
    provider->manufacturer=malloc(sizeof(manufacturer));
    provider->manufacturer=newManufacturer(manufacturer->name,manufacturer->description,manufacturer->direction,manufacturer->city,manufacturer->phone,manufacturer->web);

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

void askForAppliances(Provider* provider1,Stock* stock){
    if(provider1->appliancesQuantity==0){
        createAppliance(provider1->manufacturer,provider1,15);
    }
    int i;
    i = provider1->appliancesQuantity/2;
    stock->quantity+=i;
    provider1->appliancesQuantity-= (i + provider1->appliancesQuantity%2);

}