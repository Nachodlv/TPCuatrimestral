//
// Created by Ignacio on 10/5/2017.
//


#include <stdlib.h>
#include <memory.h>
#include "Stock.h"
Stock* newStock(char* id, char* article){
    Stock* stock = malloc(sizeof(Stock));
    stock->id=malloc(sizeof(char)*(strlen(id)+1));
    stock->article=malloc(sizeof(char)*(strlen(article)+1));

    strcpy(stock->id,id);
    strcpy(stock->article,article);
    return stock;
}

void freeStock(Stock* stock1){
    free(stock1->id);
    free(stock1->article);
    free(stock1);
}