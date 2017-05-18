//
// Created by Gonzalo de Achaval on 18/5/17.
//
#include <stdlib.h>
#include <memory.h>
#include "Product.h"

Product* newProduct(char* name, int code, double price, char* photo, Provider* provider1, Manufacturer* manufacturer1){
    Product* product = malloc(sizeof(Product));
    product->name = malloc(sizeof(name));
    product->code = code;
    product->photo = malloc(sizeof(photo));
    product->manufacturer1 = malloc(sizeof(provider1));
    product->provider1 = malloc(sizeof(manufacturer1));
    product->price=price;
    product->manufacturer1 = newManufacturer(manufacturer1->name,manufacturer1->code);
    product->provider1 = newProvider(provider1->CIF,provider1->name,provider1->responsable,provider1->phone,provider1->address,provider1->location,provider1->province,provider1->country,provider1->postalCode,provider1->fax);
    strcpy(product->name,name);
    strcpy(product->photo,photo);
    return product;
}

void freeProduct(Product* product1){
    freeManufacturer(product1->manufacturer1);
    freeProvider(product1->provider1);
    free(product1->name);
    free(product1->photo);
    free(product1);
}
