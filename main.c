#include <stdio.h>
#include "Exercise1/Provider.h"
#include "Exercise1/Catalogue.h"
#include "Exercise1/Manufacturer.h"
#include "Exercise1/Appliance.h"

//timepo estimado: 2:15 horas + 30min
void printCatalogue(Catalogue* catalogue1);
int main() {
    Manufacturer* apple = newManufacturer("Apple","we are the best","apple st","California","1298766789","www.apple.com");
    Manufacturer* samsung = newManufacturer("Samsung","we are the best","samsung st","California","1298766789","www.samsung.com");

    Provider* applePoint = newProvider("ApplePoint","we sell apple phones","hello st","Argentina","11111","www.applepoint.com",apple);
    Provider* garbarino = newProvider("Garbarino", "hi","Unicenter","Bs AS","1111","www.garbarino.com",samsung);

    Catalogue* phones = newCatalogue("001","phones",0.2);

    addAppliance(phones,newAppliance("iphone7","plus",10000,phones->discount,applePoint));
    addAppliance(phones,newAppliance("galaxy","edge",8000,phones->discount,garbarino));

    printCatalogue(phones);
    printf("%d",1);
    printf("%s",phones->name);
    char a;
    scanf(" %c",&a );
    //perror("Error");
    char b;
    scanf(" %c",&b );
    return 0;
}

void printCatalogue(Catalogue* catalogue1){ ;
    int counter=1;
    int i;
    for(i=0;i<catalogue1->maxCapacity;i++){
        if(catalogue1->applianceBooleanArray[i]==1){
            printf("%d",counter);
            printf("%s\n",catalogue1->applianceArray[i]->name);
            counter++;
        }
    }
}