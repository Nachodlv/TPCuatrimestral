//
// Created by Ignacio on 30/5/2017.
//

#include "DataBase.h"

#ifndef TPCUATRIMESTRAL_EXCESS_H
#define TPCUATRIMESTRAL_EXCESS_H
typedef struct excess Excess;
struct exesss{
    double money;
    double costPerDay;
};

Excess* newExcess();
void freeExcess(Excess* excess);
int moviesWithoutReturn(DataBase dataBase);
#endif //TPCUATRIMESTRAL_EXCESS_H
