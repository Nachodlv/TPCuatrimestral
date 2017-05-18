//
// Created by Gonzalo de Achaval on 18/5/17.
//

#ifndef TPCUATRIMESTRAL_SALE_H
#define TPCUATRIMESTRAL_SALE_H

#include "time.h"
#include "SaleLine.h"
#include "Product.h"
typedef struct sale Sale;
struct sale{
    int code;
    double totalPrice;
    double discount;
    time_t time;
    SaleLine** saleLineArray;
    int saleLineMaxCapacity;
    int* booleanArray;
};
Sale* newSale(int code, double discount);
void freeSale(Sale* sale);
void addProduct(Sale* sale, Product* product);
void growSaleLineArray(Sale* sale);
void removeProduct(Sale* sale, int productCode);
double endShopping(Sale* sale);
#endif //TPCUATRIMESTRAL_SALE_H
