//
// Created by Gonzalo de Achaval on 18/5/17.
//

#ifndef TPCUATRIMESTRAL_MANUFACTURER_H
#define TPCUATRIMESTRAL_MANUFACTURER_H

typedef struct manufacturer Manufacturer;
struct manufacturer{
    char* name;
    int code;
};
Manufacturer* newManufacturer(char* name, int code);
void freeManufacturer(Manufacturer* manufacturer1);

#endif //TPCUATRIMESTRAL_MANUFACTURER_H
