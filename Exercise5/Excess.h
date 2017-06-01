//
// Created by Ignacio on 30/5/2017.
//

#ifndef TPCUATRIMESTRAL_EXCESS_H
#define TPCUATRIMESTRAL_EXCESS_H

#include "DataBase.h"

typedef struct excess Excess;
struct excess{
    double money;
    double costPerDay;
};

Excess* newExcess(double costOfMovieRentPerDay);
void freeExcess(Excess* excess);
int moviesWithoutReturn(DataBase dataBase);
void leaveMovie(Movie* movie, Excess* excess1);

#endif //TPCUATRIMESTRAL_EXCESS_H
