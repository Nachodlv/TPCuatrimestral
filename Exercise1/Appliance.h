
#ifndef TPCUATRIMESTRAL_APPLIANCE_H
#define TPCUATRIMESTRAL_APPLIANCE_H

typedef struct invoiceLine InvoiceLine;
typedef struct provider Provider;
typedef struct label Label;
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
void generateSpaceForAppliance(Appliance* appliance1,Provider* provider1);
#endif //TPCUATRIMESTRAL_APPLIANCE_H
