

#include <stdlib.h>
#include <memory.h>
#include "Appliance.h"
#include "Label.h"
#include "Provider.h"

Appliance* newAppliance(char* name, char* model, double price, double discount, Provider* provider1){
    Appliance* appliance = malloc(sizeof(Appliance));
    appliance->discount=discount;
    appliance->price=price;
    appliance->model = malloc(sizeof(model));
    appliance->name = malloc(sizeof(name));
    appliance->provider = malloc(sizeof(provider1));
    appliance->label = malloc(sizeof(Label));
    appliance->label = newLabel("asd",name);
    appliance->provider = malloc(sizeof(provider1));
    appliance->provider = newProvider(provider1->name,provider1->description,provider1->direction,provider1->city,provider1->phone,provider1->web,provider1->manufacturer);
    strcpy(appliance->model,model);
    strcpy(appliance->name,name);
    return appliance;
}

char* generateId(char* name, char* model){
    char* result=strcat(name,model);
    return result;
}

void freeAppliance(Appliance* appliance){
    freeProvider(appliance->provider);
    freeLabel(appliance->label);
    free(appliance->model);
    free(appliance->name);
    free(appliance->provider);
    free(appliance->label);
    free(appliance);
}

int compareTo(Appliance* appliance1,Appliance* appliance2){
    if(strcmp(appliance1->label->id,appliance2->label->id)==0){
        return 1;
    }
    return 0;

}