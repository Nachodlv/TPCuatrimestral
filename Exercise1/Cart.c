//
// Created by Ignacio on 10/5/2017.
//


#include <stdlib.h>
#include <memory.h>
#include "Cart.h"
#include "Provider.h"
#include "Appliance.h"
#include "Invoice.h"
#include "LineCart.h"
#include "InvoiceLine.h"
#include "Label.h"

Cart* newCart(char* id){
    Cart* cart1 = malloc(sizeof(Cart));
    cart1->total=0;
    cart1->id = malloc(sizeof(id));
    cart1->lineCartArray = malloc(sizeof(LineCart)*10);
    cart1->lineCartBooleanArray = malloc(sizeof(int)*10);

    strcpy(cart1->id,id);
    return cart1;
}

void freeCart(Cart* cart1){
    int maxCapacity = sizeof(cart1->lineCartArray)/ sizeof(LineCart);
    int i;
    for(i=0;i<maxCapacity;i++){
        if(cart1->lineCartBooleanArray[i]){
            free(cart1->lineCartArray[i]);
        }
    }
    free(cart1->lineCartArray);
    free(cart1->lineCartBooleanArray);
    free(cart1->id);
    free(cart1);
}

void addToCart(Cart* cart1, Appliance* appliance1){
    int maxCapacity = sizeof(cart1->lineCartArray)/ sizeof(LineCart);
    int hasInserted=0;
    if(appliance1->invoiceLineArray->quantity==0){
        askForAppliances(appliance1->provider,appliance1->invoiceLineArray);
    }
    int i;
    for(i=0;i<maxCapacity;i++){
        if(cart1->lineCartBooleanArray[i]==1) {
            if(compareTo(cart1->lineCartArray[i]->appliance1,appliance1)==0){
                cart1->lineCartArray[i]->quantity++;
                cart1->total+=appliance1->price*appliance1->discount;
            }
        } else{
            cart1->lineCartArray[i] = newLineCart(appliance1->label->id,appliance1);
            cart1->lineCartBooleanArray[i]=1;
            cart1->total+=appliance1->price*appliance1->discount;
            hasInserted=1;
            break;
        }
    }
    if(!hasInserted){
        growCart(cart1);
        addToCart(cart1,appliance1);
    }
}

void growCart(Cart* cart1){
    int maxCapacity = sizeof(cart1->lineCartArray)/ sizeof(LineCart);
    cart1->lineCartArray = realloc(cart1->lineCartArray, sizeof(LineCart)*maxCapacity*2);
    cart1->lineCartBooleanArray=realloc(cart1->lineCartBooleanArray, sizeof(int)*maxCapacity*2);
}

Appliance* erraseAppliance(Cart* cart1, Appliance* appliance1){
    int maxCapacity = sizeof(cart1->lineCartArray)/ sizeof(LineCart);
    int i;
    for(i=0;i<maxCapacity;i++){
        if(cart1->lineCartBooleanArray[i]){
            if(compareTo(cart1->lineCartArray[i]->appliance1,appliance1)){
                cart1->lineCartArray[i]->quantity--;
                if(cart1->lineCartArray[i]->quantity==0){
                    cart1->lineCartBooleanArray[i]=0;
                }
                return cart1->lineCartArray[i]->appliance1;
            }
        }
    }
    exit(2);
}

Invoice* finishShopping(Cart* cart){
    return newInvoice(cart->id,cart->total);
}


