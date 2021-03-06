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
#include "Stock.h"
#include "Label.h"

Cart* newCart(int id){
    Cart* cart1 = malloc(sizeof(Cart));
    cart1->total=0;
    cart1->id = id;
    cart1->lineCartArray = malloc(sizeof(LineCart)*10);
    cart1->lineCartBooleanArray = malloc(sizeof(int)*10);
    cart1->maxCapacity=10;

    for(int i=0;i<cart1->maxCapacity;i++){
        cart1->lineCartBooleanArray[i]=0;
    }
    return cart1;
}

void freeCart(Cart* cart1){
    int i;
    for(i=0;i<cart1->maxCapacity;i++){
        if(cart1->lineCartBooleanArray[i]){
            free(cart1->lineCartArray[i]);
        }
    }
    free(cart1->lineCartArray);
    free(cart1->lineCartBooleanArray);
    free(cart1);
}

void addToCart(Cart* cart1, Appliance* appliance1){
    int hasInserted=0;
    if(appliance1->stock->quantity==0){
        askForAppliances(appliance1->provider,appliance1->stock);
    }
    int i;
    for(i=0;i<cart1->maxCapacity;i++){
        if(cart1->lineCartBooleanArray[i]==1) {
            if(compareTo(cart1->lineCartArray[i]->appliance1,appliance1)==1){
                cart1->lineCartArray[i]->quantity++;
                cart1->total+=appliance1->price*appliance1->discount+appliance1->price;
                hasInserted=1;
                break;
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
    cart1->lineCartArray = realloc(cart1->lineCartArray, sizeof(LineCart)*cart1->maxCapacity*2);
    cart1->lineCartBooleanArray=realloc(cart1->lineCartBooleanArray, sizeof(int)*cart1->maxCapacity*2);
    for(int i=cart1->maxCapacity;i<cart1->maxCapacity*2;i++){
        cart1->lineCartBooleanArray[i]=0;
    }
    cart1->maxCapacity=cart1->maxCapacity*2;
}

Appliance* erraseAppliance(Cart* cart1, Appliance* appliance1){
    int i;
    for(i=0;i<cart1->maxCapacity;i++){
        if(cart1->lineCartBooleanArray[i]){
            if(compareTo(cart1->lineCartArray[i]->appliance1,appliance1)){
                cart1->lineCartArray[i]->quantity--;
                cart1->total-=cart1->lineCartArray[i]->appliance1->price*cart1->lineCartArray[i]->appliance1->discount;
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
    Invoice* invoice1= newInvoice(cart->id,cart->total,cart->maxCapacity);
    for(int i=0;i<cart->maxCapacity;i++){
        if(cart->lineCartBooleanArray[i]==1){
            addInvoiceLine(invoice1,newInvoiceLine(cart->lineCartArray[i]->quantity,cart->lineCartArray[i]->appliance1->name));
        }
    }
    return invoice1;
}


