//
// Created by Gonzalo de Achaval on 18/5/17.
//

#include "SaleLine.h"
#include <stdlib.h>
SaleLine* newSaleLine(Product* product, int quantity){
    SaleLine* saleLine1 = malloc(sizeof(SaleLine));
    saleLine1->product = malloc(sizeof(Product));
    saleLine1->quantity=quantity;
    saleLine1->product = newProduct(product->name,product->code,product->price,product->photo,product->provider1,product->manufacturer1);
    return saleLine1;
}


