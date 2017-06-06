//
// Created by Ignacio on 14/5/2017.
//

#include <stdlib.h>
#include <memory.h>
#include "InvoiceLine.h"

InvoiceLine* newInvoiceLine(int quantity, char* article){
    InvoiceLine* invoiceLine = malloc(sizeof(InvoiceLine));
    invoiceLine->quantity=quantity;
    invoiceLine->article=malloc(sizeof(char)*(strlen(article)+1));
    strcpy(invoiceLine->article,article);
    return invoiceLine;
}

void freeInvoiceLine(InvoiceLine* invoiceLine){
    free(invoiceLine->article);
    free(invoiceLine);
}