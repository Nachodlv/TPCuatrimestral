//
// Created by Gonzalo de Achaval on 18/5/17.
//

#include "Sale.h"
#include <stdlib.h>
#include <memory.h>

Sale* newSale(int code, double discount){
    Sale* sale = malloc(sizeof(Sale));
    sale->code=code;
    sale->discount=discount;
}

