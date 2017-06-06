//
// Created by Gonzalo de Achaval on 18/5/17.
//

#include "Provider.h"
#include <stdlib.h>
#include <memory.h>
Provider* newProviderExercise2(char* CIF, char* name, char* responsable, char* phone, char* address, char* location, char* province, char* country, char* postalCode, char* fax){
    Provider* provider1 = malloc(sizeof(Provider));
    provider1->CIF = malloc(sizeof(char)*(strlen(CIF)+1));
    provider1->name = malloc(sizeof(char)*(strlen(name)+1));
    provider1->responsable = malloc(sizeof(char)*(strlen(responsable)+1));
    provider1->phone = malloc(sizeof(char)*(strlen(phone)+1));
    provider1->address = malloc(sizeof(char)*(strlen(address)+1));
    provider1->location = malloc(sizeof(char)*(strlen(location)+1));
    provider1->province = malloc(sizeof(char)*(strlen(province)+1));
    provider1->country = malloc(sizeof(char)*(strlen(country)+1));
    provider1->postalCode = malloc(sizeof(char)*(strlen(postalCode)+1));
    provider1->fax = malloc(sizeof(char)*(strlen(fax)+1));
    strcpy(provider1->CIF,CIF);
    strcpy(provider1->name,name);
    strcpy(provider1->responsable,responsable);
    strcpy(provider1->phone,phone);
    strcpy(provider1->address,address);
    strcpy(provider1->location,location);
    strcpy(provider1->province,province);
    strcpy(provider1->country,country);
    strcpy(provider1->postalCode,postalCode);
    strcpy(provider1->fax,fax);
    return provider1;
}

void freeProviderExercise2(Provider* provider1){
    free(provider1->CIF);
    free(provider1->name);
    free(provider1->responsable);
    free(provider1->phone);
    free(provider1->address);
    free(provider1->location);
    free(provider1->province);
    free(provider1->country);
    free(provider1->postalCode);
    free(provider1->fax);
    free(provider1);
}

