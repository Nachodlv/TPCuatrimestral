//
// Created by Ignacio on 10/5/2017.
//


#include <stdlib.h>
#include <memory.h>
#include "Catalogue.h"
Catalogue* newCatalogue(char* id,char* name, double discount){
    Catalogue* catalogue1 = malloc(sizeof(Catalogue));
    catalogue1->id = malloc(sizeof(id));
    catalogue1->name = malloc(sizeof(name));
    catalogue1->discount=discount;
    catalogue1->applianceArray = malloc(sizeof(Appliance)*10);
    catalogue1->applianceBooleanArray = malloc(sizeof(int)*10);

    strcpy(catalogue1->id,id);
    strcpy(catalogue1->name,name);
    return catalogue1;
}

void freeCatalogue(Catalogue* catalogue1){
    int maxCapacity = sizeof(catalogue1->applianceArray)/ sizeof(Appliance);
    for (int i = 0; i <maxCapacity; i++) {
        if(catalogue1->applianceBooleanArray[i]==1){
            freeAppliance(catalogue1->applianceArray[i]);
        }
    }
    free(catalogue1->applianceArray);
    free(catalogue1->applianceBooleanArray);
    free(catalogue1->id);
    free(catalogue1->name);
    free(catalogue1);
}

void addAppliance(Catalogue* catalogue1,Appliance* appliance1){
    int maxCapacity = sizeof(catalogue1->applianceArray)/ sizeof(Appliance);
    int hasInserted=0;
    for(int i=0;i<maxCapacity;i++){
        if(catalogue1->applianceBooleanArray[i]==0) {
            catalogue1->applianceArray[i] = appliance1;
            catalogue1->applianceBooleanArray[i] = 1;
            hasInserted = 1;
            break;
        }
    }
    if(!hasInserted){
        grow(catalogue1);
        addAppliance(catalogue1,appliance1);
    }
}

void grow(Catalogue* catalogue1){
    int maxCapacity = sizeof(catalogue1->applianceArray)/ sizeof(Appliance);
    catalogue1->applianceArray = realloc(catalogue1->applianceArray, sizeof(Appliance)*maxCapacity*2);
    catalogue1->applianceBooleanArray=realloc(catalogue1->applianceBooleanArray, sizeof(int)*maxCapacity*2);
}

Appliance* removeAppliance(Catalogue* catalogue1,Appliance* appliance1){
    int maxCapacity = sizeof(catalogue1->applianceArray)/ sizeof(Appliance);
    for(int i=0;i<maxCapacity;i++){
        if(catalogue1->applianceBooleanArray[i]==1){
            if(compareTo(catalogue1->applianceArray[i],appliance1)==1){
                catalogue1->applianceBooleanArray[i]=0;
                return catalogue1->applianceArray[i];
            }
        }
    }
    exit(2);
}
