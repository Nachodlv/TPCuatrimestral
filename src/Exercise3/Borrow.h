//
// Created by Ignacio on 19/5/2017.
//

#ifndef TPCUATRIMESTRAL_BORROW_H
#define TPCUATRIMESTRAL_BORROW_H

#include <time.h>
typedef struct borrow Borrow;
struct borrow{
    int code;
    time_t departureDate;
    int returnDays;
    double price;
    int personCode;
    char* materialName;
};
Borrow* newBorrow(double price, int returnDays, char* materialName);
void freeBorrow(Borrow* borrow);


#endif //TPCUATRIMESTRAL_BORROW_H
