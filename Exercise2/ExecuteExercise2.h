//
// Created by Gonzalo de Achaval on 18/5/17.
//

#include "RegisteredUser.h"
#include "Product.h"
#include "CameraAndAccesoryTable.h"
#include "Sale.h"
#include "Product.h"
#include "Camera.h"
#include "CameraAndAccesoryTable.h"
#include "Sale.h"
#include "../Exercise1/Manufacturer.h"
#include "Accesory.h"


#ifndef TPCUATRIMESTRAL_EXECUTEEXERCISE2_H
#define TPCUATRIMESTRAL_EXECUTEEXERCISE2_H

void printUsersArray(RegisteredUser** pUser, int usersQuantity);
RegisteredUser* chooseUser(RegisteredUser** pUser);
void printProductsArray(Product** pProduct, int productsQuantity);
int chooseProduct();
void printProductInfo(Product* product);
void printProductInfo(Product* product);
void printSpecificInfo(Product *pProduct, CameraAndAccesoryTable *pTable);
char* getCameraType(Camera *camera);
char* getAccesoryType(Accesory* accesory1);
Sale* menuAndExit(int productQuantity, Product** pProduct, Sale* sale, CameraAndAccesoryTable* table);
void productMenu(Product* pProduct, Sale* sale);
void printProviderInfo(Product *pProduct);
void printManufacturerInfo(Product *pProduct);
void printMenu();
void printAccesoryInfo(Accesory* accesory);
void printCameraInfo(Camera* camera);

#endif //TPCUATRIMESTRAL_EXECUTEEXERCISE2_H
