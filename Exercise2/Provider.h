//
// Created by Gonzalo de Achaval on 18/5/17.
//

#ifndef TPCUATRIMESTRAL_PROVIDER_H
#define TPCUATRIMESTRAL_PROVIDER_H

typedef struct provider Provider;
struct provider{
    char* CIF;
    char* name;
    char* phone;
    char* fax;
    char* responsable;
    char* address;
    char* location;
    char* province;
    char* country;
    char* postalCode;
};

Provider* newProviderExercise2(char* CIF, char* name, char* responsable, char* phone, char* address, char* location, char* province, char* country, char* postalCode, char* fax);
void freeProviderExercise2(Provider* provider1);

#endif //TPCUATRIMESTRAL_PROVIDER_H
