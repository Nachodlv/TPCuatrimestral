//
// Created by Ignacio on 10/5/2017.
//

#ifndef TPCUATRIMESTRAL_LINECART_H
#define TPCUATRIMESTRAL_LINECART_H


typedef struct appliance Appliance;
typedef struct lineCart LineCart;
struct lineCart{
    char* id;
    Appliance* appliance1;
    int quantity;
};
LineCart* newLineCart(char* id, Appliance* appliance1);
void freeLineCart(LineCart* lineCart1);

#endif //TPCUATRIMESTRAL_LINECART_H
