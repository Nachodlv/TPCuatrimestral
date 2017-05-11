//
// Created by Ignacio on 10/5/2017.
//

#include <malloc.h>
#include <mem.h>
#include "Cart.h"
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
    for(int i=0;i<maxCapacity;i++){
        if(cart1->lineCartBooleanArray[i]){
            free(cart1->lineCartArray[i]);
        }
    }
    free(cart1->lineCartArray);
    free(cart1->lineCartBooleanArray);
    free(cart1->id);
    free(cart1);
}

void addAppliance(Cart* cart1, Appliance* appliance1){
    int maxCapacity = sizeof(cart1->lineCartArray)/ sizeof(LineCart);
    int hasInserted=0;
    for(int i=0;i<maxCapacity;i++){
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
        grow(cart1);
        addAppliance(cart1,appliance1);
    }
}

void grow(Cart* cart1){
    int maxCapacity = sizeof(cart1->lineCartArray)/ sizeof(LineCart);
    cart1->lineCartArray = realloc(cart1->lineCartArray, sizeof(LineCart)*maxCapacity*2);
    cart1->lineCartBooleanArray=realloc(cart1->lineCartBooleanArray, sizeof(int)*maxCapacity*2);
}

Appliance* erraseAppliance(Cart* cart1, Appliance* appliance1){
    int maxCapacity = sizeof(cart1->lineCartArray)/ sizeof(LineCart);
    for(int i=0;i<maxCapacity;i++){
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


