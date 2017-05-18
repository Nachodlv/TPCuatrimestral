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
    sale->saleLineArray=malloc(sizeof(SaleLine)*10);
    sale->saleLineMaxCapacity=10;
    sale->booleanArray=malloc(sizeof(int)*10);
    for(int i=0;i<10;i++){
        sale->booleanArray[i]=0;
    }
    return sale;
}

void freeSale(Sale* sale){
    for(int i=0;i<sale->saleLineMaxCapacity;i++){
        if(sale->booleanArray[i]==1) freeSaleLine(sale->saleLineArray[i]);
    }
    free(sale->saleLineArray);
    free(sale->booleanArray);
    free(sale);
}

void addProduct(Sale* sale, Product* product){
    int hasAdded=0;
    for(int i=0;i<sale->saleLineMaxCapacity;i++){
        if(sale->booleanArray[i]==1){
            if(sale->saleLineArray[i]->product->code==product->code){
                sale->saleLineArray[i]->quantity++;
                return;
            }
        }
    }
    for(int i=0;i<sale->saleLineMaxCapacity;i++){
        if(sale->booleanArray[i]==0){
            sale->saleLineArray[i]=newSaleLine(product,1);
            return;
        }
    }
    growSaleLineArray(sale);
    addProduct(sale,product);
}

void growSaleLineArray(Sale* sale){
    sale->saleLineArray = realloc(sale->saleLineArray, sizeof(SaleLine)*sale->saleLineMaxCapacity*2);
    sale->booleanArray=realloc(sale->booleanArray, sizeof(int)*sale->saleLineMaxCapacity*2);
    for(int i=sale->saleLineMaxCapacity;i<sale->saleLineMaxCapacity*2;i++){
        sale->booleanArray[i]=0;
    }
    sale->saleLineMaxCapacity=sale->saleLineMaxCapacity*2;
}

void removeProduct(Sale* sale, int productCode){
    for(int i=0;i<sale->saleLineMaxCapacity;i++){
        if(sale->booleanArray[i]==1){
            if(sale->saleLineArray[i]->product->code==productCode){
                sale->saleLineArray[i]->quantity--;
                if(sale->saleLineArray[i]->quantity==0){
                    sale->booleanArray[i]=0;
                }
            }
        }
    }
}

double endShopping(Sale* sale){
    double total=0;
    sale->time=time(0);
    for(int i=0;i<sale->saleLineMaxCapacity;i++){
        if(sale->booleanArray[i]==1){
            total+=sale->saleLineArray[i]->product->price*sale->discount*sale->saleLineArray[i]->quantity;
        }
    }
    return total;
}


