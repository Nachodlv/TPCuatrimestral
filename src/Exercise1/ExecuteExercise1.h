//
// Created by Oscar on 16/05/2017.
//

#ifndef TPCUATRIMESTRAL_EXECUTEEXERCISE1_H
#define TPCUATRIMESTRAL_EXECUTEEXERCISE1_H
#include "Provider.h"
#include "Catalogue.h"
#include "Manufacturer.h"
#include "Appliance.h"
#include "Cart.h"
#include "LineCart.h"
#include "Invoice.h"

int executeExercise1();
void printAppliances(Catalogue* catalogue1);
void printCatalogues(Catalogue** catalogueArray, int cataloguesQuantity);
void startShopping(Catalogue** catalogueArray,int cataloguesQuantity, Cart* cart1);
void mainMenu(Catalogue** catalogueArray,int cataloguesQuantity, Cart* cart1);
void stopShopping(Cart* cart1);
void seeCart(Cart* cart1);
#endif //TPCUATRIMESTRAL_EXECUTEEXERCISE1_H
