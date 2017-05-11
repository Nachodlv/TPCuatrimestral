//
// Created by Ignacio on 10/5/2017.
//

#include <stdlib.h>
#include <memory.h>
#include "Invoice.h"
Invoice* newInvoice(char* id, double toPay){
    Invoice* invoice1 = malloc(sizeof(Invoice));
    invoice1->id = malloc(sizeof(id));
    invoice1->toPay=toPay;

    strcpy(invoice1->id,id);
    return invoice1;
}

void freeInvoice(Invoice* invoice1){
    free(invoice1->id);
    free(invoice1);
}