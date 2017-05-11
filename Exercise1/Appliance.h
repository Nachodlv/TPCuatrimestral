
#ifndef TPCUATRIMESTRAL_APPLIANCE_H
#define TPCUATRIMESTRAL_APPLIANCE_H

#include "InvoiceLine.h"
#include "Provider.h"
#include "Label.h"

typedef struct appliance Appliance;
struct appliance{
    char* name;
    char* model;
    double price;
    InvoiceLine* invoiceLineArray;
    double discount;
    Provider* provider;
    Label* label;
};
Appliance* newAppliance(char* name, char* model, double price, double discount, Provider* provider);
void freeAppliance(Appliance* appliance);
char* generateId(char* name, char* model);
int compareTo(Appliance* appliance1,Appliance* appliance2);
#endif //TPCUATRIMESTRAL_APPLIANCE_H
