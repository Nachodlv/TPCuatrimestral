//
// Created by Gonzalo de Achaval on 18/5/17.
//

#ifndef TPCUATRIMESTRAL_ACCESORY_H
#define TPCUATRIMESTRAL_ACCESORY_H
typedef struct accesory Accesory;
struct accesory{
    int accesoryType;
    char* comment;
    int code;
};
Accesory* newAccesory(int accesoryType, char* comment, int code);
void freeAccesory(Accesory* accesory);
#endif //TPCUATRIMESTRAL_ACCESORY_H
