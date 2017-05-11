#include <stdio.h>
#include "Exercise1/Provider.h"
#include "Exercise1/Catalogue.h"
//timepo estimado: 2:15 horas + 30min
int main() {
    Manufacturer* apple = newManufacturer("Apple","we are the best","apple st","California","1298766789","www.apple.com");
    Manufacturer* samsung = newManufacturer("Samsung","we are the best","samsung st","California","1298766789","www.samsung.com");

    Provider* applePoint = newProvider("ApplePoint","we sell apple phones","hello st","Argentina","11111","www.applepoint.com",apple);
    Provider* garbarino = newProvider("Garbarino", "hi","Unicenter","Bs AS","1111","www.garbarino.com",samsung);

    Catalogue* phones = newCatalogue("001","phones",0.2);

    addAppliance(phones,newAppliance("iphone7","plus",10000,phones->discount,applePoint));
    addAppliance(phones,newAppliance("galaxy","edge",8000,phones->discount,garbarino));

}