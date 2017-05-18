//
// Created by Gonzalo de Achaval on 18/5/17.
//

#ifndef TPCUATRIMESTRAL_SALELINE_H
#define TPCUATRIMESTRAL_SALELINE_H

#include "Product.h"
typedef struct saleLine SaleLine;
struct saleLine{
    int quantity;
    Product* product;
};
SaleLine* newSaleLine(Product* product, int quantity);
void freeSaleLine(SaleLine* saleLine);
#endif //TPCUATRIMESTRAL_SALELINE_H
