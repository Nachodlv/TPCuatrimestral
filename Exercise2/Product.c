//
// Created by Gonzalo de Achaval on 18/5/17.
//
#include <stdlib.h>
#include <memory.h>
#include "Product.h"

Product* newProduct(char* name, int code, double price, char* photo, Provider* provider1, Manufacturer* manufacturer1){
    Product* product = malloc(sizeof(Product));
    product->name = malloc(sizeof(char)*(strlen(name)+1));
    product->code = code;
    product->photo = malloc(sizeof(char)*(strlen(photo)+1));
    product->manufacturer1 = malloc(sizeof(provider1));
    product->provider1 = malloc(sizeof(manufacturer1));
    product->price=price;
    product->manufacturer1 = newManufacturerExercise2(manufacturer1->name,manufacturer1->code);
    product->provider1 = newProviderExercise2(provider1->CIF,provider1->name,provider1->responsable,provider1->phone,provider1->address,provider1->location,provider1->province,provider1->country,provider1->postalCode,provider1->fax);
    strcpy(product->name,name);
    strcpy(product->photo,photo);
    return product;
}

void freeProduct(Product* product1){
    freeManufacturerExercise2(product1->manufacturer1);
    freeProviderExercise2(product1->provider1);
    free(product1->name);
    free(product1->photo);
    free(product1);
}
