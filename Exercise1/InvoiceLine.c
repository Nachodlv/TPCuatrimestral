//
// Created by Ignacio on 10/5/2017.
//


#include <stdlib.h>
#include <memory.h>
#include "InvoiceLine.h"
InvoiceLine* newInvoiceLine(char* id, char* article){
    InvoiceLine* invoiceLine1 = malloc(sizeof(InvoiceLine));
    invoiceLine1->id=malloc(sizeof(id));
    invoiceLine1->article=malloc(sizeof(article));

    strcpy(invoiceLine1->id,id);
    strcpy(invoiceLine1->article,article);
    return invoiceLine1;
}

void freeInvoiceLine(InvoiceLine* invoiceLine1){
    free(invoiceLine1->id);
    free(invoiceLine1->article);
    free(invoiceLine1);
}