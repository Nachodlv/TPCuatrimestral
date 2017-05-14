//
// Created by Ignacio on 10/5/2017.
//

#ifndef TPCUATRIMESTRAL_STOCK_H
#define TPCUATRIMESTRAL_STOCK_H
typedef struct stock Stock;
struct stock{
    char* id;
    char* article;
    int quantity;
};
Stock* newStock(char* id, char* article);
void freeStock(Stock* stock1);


#endif //TPCUATRIMESTRAL_STOCK_H
