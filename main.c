#include <stdio.h>
#include <malloc.h>
#include "Exercise1/Provider.h"
#include "Exercise1/Catalogue.h"
#include "Exercise1/Manufacturer.h"
#include "Exercise1/Appliance.h"
#include "Exercise1/Cart.h"
#include "Exercise1/LineCart.h"
#include "Exercise1/Invoice.h"

//timepo estimado: 2:15 horas + 30min
void printAppliances(Catalogue* catalogue1);
void printCatalogues(Catalogue** catalogueArray, int cataloguesQuantity);
void startShopping(Catalogue** catalogueArray,int cataloguesQuantity, Cart* cart1);
void mainMenu(Catalogue** catalogueArray,int cataloguesQuantity, Cart* cart1);
void stopShopping(Cart* cart1);
void seeCart(Cart* cart1);

int main() {
    Manufacturer* apple = newManufacturer("Apple","we are the best","apple st","California","1298766789","www.apple.com");
    Manufacturer* samsung = newManufacturer("Samsung","we are the best","samsung st","California","1298766789","www.samsung.com");
    Manufacturer* lgManufactuer = newManufacturer("LG","we are the best","lg st","California","1298766789","www.lg.com");

    Catalogue** catalogueArray = malloc(sizeof(Catalogue)*2);
    catalogueArray[0] = newCatalogue("001","phones",0.2);
    catalogueArray[1] = newCatalogue("002","TV",0.5);
    int cataloguesQuantity =2;

    Provider* applePoint = newProvider("ApplePoint","we sell apple phones","hello st","Argentina","11111","www.applepoint.com",apple);
    Provider* garbarino = newProvider("Garbarino", "hi","Unicenter","Bs AS","1111","www.garbarino.com",samsung);
    Provider* lgProvider = newProvider("LG", "hi","Unicenter","Bs AS","1111","www.lg.com",lgManufactuer);

    addAppliance(catalogueArray[0],newAppliance("iphone7","plus",10000,catalogueArray[0]->discount,applePoint));
    addAppliance(catalogueArray[0],newAppliance("galaxy","edge",8000,catalogueArray[0]->discount,garbarino));


    addAppliance(catalogueArray[1],newAppliance("Samsung 4K","XC-105",5000,catalogueArray[1]->discount,garbarino));
    addAppliance(catalogueArray[1],newAppliance("LG","AV",4500,catalogueArray[1]->discount,lgProvider));

    int userId;
    printf(" %s","Please enter your id: ");
    scanf(" %i*c",&userId);
    Cart* cart1 = newCart(userId);

    mainMenu(catalogueArray,cataloguesQuantity,cart1);

    return 0;
}

void printCatalogues(Catalogue** catalogueArray, int cataloguesQuantity){
    for(int i=0;i< cataloguesQuantity;i++){
        printf(" %d\t",i+1);
        printf("%s\n",catalogueArray[i]->name);
    }
}

void printAppliances(Catalogue* catalogue1){
    int counter=1;
    int i;
    for(i=0;i<catalogue1->maxCapacity;i++){
        if(catalogue1->applianceBooleanArray[i]==1){
            printf("%d\t",counter);
            printf("%s",catalogue1->applianceArray[i]->name);
            printf("%s", " ~ ");
            printf("%f\n",catalogue1->applianceArray[i]->price*catalogue1->applianceArray[i]->discount);
            counter++;
        }
    }
}

void mainMenu(Catalogue** catalogueArray,int cataloguesQuantity, Cart* cart1){
    int whileBoolean=1;
    while(whileBoolean){
        int result;
        printf("%s\n","1. Start shopping");
        printf("%s\n","2. Delete a product from the cart");
        printf("%s\n","3. Finish Shopping");
        printf("%s\n","4. Exit");
        printf(" %s","Choose an option: ");
        scanf(" %i*c",&result);
        switch (result){
            case 1:
                startShopping(catalogueArray,cataloguesQuantity,cart1);
                break;
            case 2:
                seeCart(cart1);
                break;
            case 3:
                stopShopping(cart1);
                whileBoolean=0;
                break;
            case 4:
                whileBoolean=0;
                break;
            default:
                printf("%s\n", "Choose a valid option");
                mainMenu(catalogueArray,cataloguesQuantity,cart1);
                break;
        }
    }
}

void startShopping(Catalogue** catalogueArray,int cataloguesQuantity, Cart* cart1){
    printCatalogues(catalogueArray,cataloguesQuantity);
    printf(" %i\t",cataloguesQuantity+1);
    printf(" %s\n","Back");

    int option;
    printf(" %s","Choose a catalogue: ");
    scanf(" %i*c\n",&option);
    if(option==cataloguesQuantity+1){
        return;
    }
    printAppliances(catalogueArray[option-1]);

    int option2;
    printf(" %s","Choose an appliance to add to the cart: ");
    scanf(" %i*c",&option2);

    addToCart(cart1,catalogueArray[option-1]->applianceArray[option2-1]);
    startShopping(catalogueArray,cataloguesQuantity,cart1);
}

void seeCart(Cart* cart1){
    int counter=1;
    for(int i=0;i<cart1->maxCapacity;i++){
        if(cart1->lineCartBooleanArray[i]==1){
            printf("%i\t",counter);
            printf("%s\n",cart1->lineCartArray[i]->appliance1->name);
            counter++;
        }
    }
    printf("%i\t", counter);
    printf("%s\n", "Back");
    int result;
    printf("%s","Choose an option: ");
    scanf(" %i*c", &result);
    if(result==counter) return;
    erraseAppliance(cart1,cart1->lineCartArray[result-1]->appliance1);
}

void stopShopping(Cart* cart1){
    Invoice* invoice1 = finishShopping(cart1);
    printf("%s%i\n", "User: ", invoice1->id);
    printf("%s%f\n","To pay: ", invoice1->toPay);
    int a;
    printf("%s","Enter any letter to continue: ");
    scanf("%i",&a);
};

