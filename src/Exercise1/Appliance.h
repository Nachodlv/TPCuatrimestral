
#ifndef TPCUATRIMESTRAL_APPLIANCE_H
#define TPCUATRIMESTRAL_APPLIANCE_H

typedef struct stock Stock;
typedef struct provider Provider;
typedef struct label Label;
typedef struct appliance Appliance;
struct appliance{
    char* name;
    char* model;
    double price;
    Stock* stock;
    double discount;
    Provider* provider;
    Label* label;
};
Appliance* newAppliance(char* name, char* model, double price, double discount, Provider* provider);
void freeAppliance(Appliance* appliance);
int compareTo(Appliance* appliance1,Appliance* appliance2);
#endif //TPCUATRIMESTRAL_APPLIANCE_H
