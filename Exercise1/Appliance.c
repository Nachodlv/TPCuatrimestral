

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
    generateSpaceForAppliance(appliance,provider1);
    strcpy(appliance->model,model);
    strcpy(appliance->name,name);
    return appliance;
}

void generateSpaceForAppliance(Appliance* appliance1,Provider* provider1){
    appliance1->provider->appliancesQuantity=0;
    appliance1->provider->city=malloc(sizeof(provider1->city));
    appliance1->provider->name=malloc(sizeof(provider1->name));
    appliance1->provider->description=malloc(sizeof(provider1->description));
    appliance1->provider->direction=malloc(sizeof(provider1->direction));
    appliance1->provider->phone=malloc(sizeof(provider1->phone));
    appliance1->provider->web=malloc(sizeof(provider1->web));
    appliance1->provider->manufacturer=malloc(sizeof(provider1->manufacturer));
    setSpaceForProvider(appliance1->provider,provider1->manufacturer);

    strcpy(appliance1->provider->city,provider1->city);
    strcpy(appliance1->provider->name,provider1->name);
    strcpy(appliance1->provider->description,provider1->description);
    strcpy(appliance1->provider->direction,provider1->direction);
    strcpy(appliance1->provider->phone,provider1->phone);
    strcpy(appliance1->provider->web,provider1->web);
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