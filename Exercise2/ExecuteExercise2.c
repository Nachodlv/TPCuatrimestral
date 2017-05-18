//
// Created by Gonzalo de Achaval on 18/5/17.
//

#include <stdio.h>
#include <stdlib.h>
#include "ExecuteExercise2.h"



int executeExercise2(){

    int usersQuantity = 3;
    RegisteredUser* user1 = newResgisteredUser("Gonza", "1", "A", "2", "B", "C", "D", "3");
    RegisteredUser* user2 = newResgisteredUser("Nacho", "11", "AA", "22", "BB", "CC", "DD", "33");
    RegisteredUser* user3 = newResgisteredUser("Gocho", "111", "AAA", "222", "BBB", "CCC", "DDD", "333");
    RegisteredUser** registeredUsers = malloc(sizeof(RegisteredUser)*usersQuantity);
    registeredUsers[0] = user1;
    registeredUsers[1] = user2;
    registeredUsers[2] = user3;

    Manufacturer* manufacturer1 = newManufacturer("Hector", 1);
    Manufacturer* manufacturer2 = newManufacturer("Victor", 2);

    Provider* provider1 = newProvider("CIF", "Gianni", "Edu", "1", "A", "B", "C", "D", "2", "3");
    Provider* provider2 = newProvider("CIF2", "Edu", "Gianni", "1", "A", "B", "C", "D", "2", "3");

    int productQuantity = 4;
    Product* product1 = newProduct("NIKON", 1, 100, "A", provider1, manufacturer1);
    Product* product2 = newProduct("CANON", 2, 200, "B", provider2, manufacturer2);
    Product* product3 = newProduct("LENTE 1", 3, 111, "A", provider1, manufacturer1);
    Product* product4 = newProduct("LENTE 2", 4, 222, "AA", provider2, manufacturer2);
    Product** products = malloc(sizeof(Product)*productQuantity);
    products[0] = product1;
    products[1] = product2;
    products[2] = product3;
    products[3] = product4;

    CameraAndAccesoryTable* cameraAndAccesoryTable1 = newCameraAndAccesoryTable();

    Accesory* accesory1 = newAccesory(1, "Este es lente 1", 3);
    Accesory* accesory2 = newAccesory(2, "Este es lente 2", 4);
    Camera* camera1 = newCamera(11, 22, 33, 1, 1);
    Camera* camera2 = newCamera(111, 222, 333, 2, 2);

    addAccesoryToCamera(camera1, accesory1);
    addAccesoryToCamera(camera1, accesory2);

    addCameraToTable(cameraAndAccesoryTable1, camera1);
    addCameraToTable(cameraAndAccesoryTable1, camera2);
    addAccesoryToTable(cameraAndAccesoryTable1, accesory1);
    addAccesoryToTable(cameraAndAccesoryTable1, accesory2);

    Sale* sale1 = newSale(1, 20);


    printUsersArray(registeredUsers, usersQuantity);
    chooseUser(registeredUsers);
    menuAndExit(productQuantity, products, sale1, cameraAndAccesoryTable1);

    return 0;
}

void printUsersArray(RegisteredUser** pUser, int usersQuantity) {
    for(int i=0;i<usersQuantity;i++){
        printf(" %d\t", i+1);
        printf("%s\n", pUser[i]->name);
    }
}

RegisteredUser* chooseUser(RegisteredUser** pUser){
    int userNumber;
    printf("%s\n", "Choose valid option: \n");
    scanf(" %i*c",&userNumber);
    return pUser[userNumber-1];
}

void printProductsArray(Product** pProduct, int productsQuantity) {
    for(int i=0; i<productsQuantity; i++){
        printf(" %d\t", i+1);
        printf("%s\n", pProduct[i]->name);
    }
    printf(" %d\t", productsQuantity+1);
    printf("%s\n", "Exit");
}

int chooseProduct() {
    int productNumber;
    printf("%s\n", "Choose valid option: \n");
    scanf(" %i*c",&productNumber);
    return productNumber-1;
}

void printProductInfo(Product* product) {
    printf("%s\n", product->name);
    printf("%f\n", product->price);
}

Sale* menuAndExit(int productQuantity, Product** pProduct, Sale* sale, CameraAndAccesoryTable* table) {

    while(1) {
        printProductsArray(pProduct, productQuantity);
        int index = chooseProduct();
        if(index==productQuantity) break; //opcion exit
        printProductInfo(pProduct[index]);
        printSpecificInfo(pProduct[index], table);
        productMenu(pProduct[index], sale);
    }
    return sale;
}

void printSpecificInfo(Product *pProduct, CameraAndAccesoryTable *pTable) {
    if(isCamera(pTable, pProduct->code)) {
        printCameraInfo(getCamera(pTable, pProduct->code));
    }
    if(isAccesory(pTable, pProduct->code)) {
        printAccesoryInfo(getAccesory(pTable, pProduct->code));
    }
}

void printCameraInfo(Camera* camera) {
    printf("%s, %d\n", "Screen: ", camera->lcdScreen);
    printf("%s, %d\n", "Max capacity: ", camera->maxCapacity);
    printf("%s, %d\n", "Mega pixels: ", camera->megaPixels);
    printf("%s, %d\n", "Optic zoom: ", camera->opticZoom);
    printf("%s, %s\n", "Type: ", getCameraType(camera));
}

char* getCameraType(Camera* camera) {
    if(camera->type == 1) return "TYPE 1";
    if(camera->type == 2) return "TYPE 2";
    return "UNDEF TYPE";
}

void printAccesoryInfo(Accesory* accesory) {
    printf("%s\n", accesory->comment);
    printf("%s, %s\n", "Type: ", getAccesoryType(accesory));
}

char* getAccesoryType(Accesory* accesory1) {
    if(accesory1->accesoryType== 1) return "TYPE 1";
    if(accesory1->accesoryType == 2) return "TYPE 2";
    return "UNDEF TYPE";
}

void productMenu(Product* pProduct, Sale* sale) {

    int trueFalse = 1;
    while(trueFalse){
        printMenu();
        int index;
        printf("%s\n", "Choose valid option: \n");
        scanf(" %i*c",&index);

        switch(index) {
            case 1:
                printProviderInfo(pProduct);
                break;
            case 2:
                printManufacturerInfo(pProduct);
                break;
            case 3:
                addProduct(sale, pProduct);
                break;
            case 4:
                trueFalse = 0;
                break;
            default: break;
        }
    }
}

void printProviderInfo(Product *pProduct) {
    printf("%s\n", pProduct->provider1->name);
    printf("%s\n", pProduct->provider1->CIF);
    printf("%s\n", pProduct->provider1->phone);
    printf("%s\n", pProduct->provider1->address);
}

void printManufacturerInfo(Product *pProduct) {
    printf("%s\n", pProduct->manufacturer1->name);
}

void printMenu() {
    printf(" %d\t", 1);
    printf("%s\n", "Show info Provider");
    printf(" %d\t", 2);
    printf("%s\n", "Show info Manufacturer");
    printf(" %d\t", 3);
    printf("%s\n", "Buy");
    printf(" %d\t", 4);
    printf("%s\n", "Back");
}






