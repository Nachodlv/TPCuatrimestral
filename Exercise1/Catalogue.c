//
// Created by Ignacio on 10/5/2017.
//


#include <stdlib.h>
#include <memory.h>
#include "Catalogue.h"
#include "Appliance.h"

Catalogue* newCatalogue(char* id,char* name, double discount){
    Catalogue* catalogue1 = malloc(sizeof(Catalogue));
    catalogue1->id = malloc(sizeof(id));
    catalogue1->name = malloc(sizeof(name));
    catalogue1->discount=discount;
    catalogue1->applianceArray = malloc(sizeof(Appliance)*10);
    catalogue1->applianceBooleanArray = malloc(sizeof(int)*10);
    catalogue1->maxCapacity=10;
    int i;
    for(i=0;i<catalogue1->maxCapacity;i++){
        catalogue1->applianceBooleanArray[i]=0;
    }

    strcpy(catalogue1->id,id);
    strcpy(catalogue1->name,name);
    return catalogue1;
}

void freeCatalogue(Catalogue* catalogue1){
    int i;
    for (i = 0; i <catalogue1->maxCapacity; i++) {
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
    int hasInserted=0;
    int i;
    for(i=0;i<catalogue1->maxCapacity;i++){
        if(catalogue1->applianceBooleanArray[i]==0) {
            catalogue1->applianceArray[i] = appliance1;
            catalogue1->applianceBooleanArray[i] = 1;
            hasInserted = 1;
            break;
        }
    }
    if(hasInserted==0){
        growCatalogue(catalogue1);
        addAppliance(catalogue1,appliance1);
        return;
    }
}

void growCatalogue(Catalogue* catalogue1){
    catalogue1->applianceArray = realloc(catalogue1->applianceArray, sizeof(Appliance)*catalogue1->maxCapacity*2);
    catalogue1->applianceBooleanArray=realloc(catalogue1->applianceBooleanArray, sizeof(int)*catalogue1->maxCapacity*2);
    catalogue1->maxCapacity = catalogue1->maxCapacity*2;
}

Appliance* removeAppliance(Catalogue* catalogue1,Appliance* appliance1){
    int i;
    for(i=0;i<catalogue1->maxCapacity;i++){
        if(catalogue1->applianceBooleanArray[i]==1){
            if(compareTo(catalogue1->applianceArray[i],appliance1)==1){
                catalogue1->applianceBooleanArray[i]=0;
                return catalogue1->applianceArray[i];
            }
        }
    }
    exit(2);
}
