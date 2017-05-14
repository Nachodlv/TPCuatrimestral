//
// Created by Ignacio on 10/5/2017.
//

#include <stdlib.h>
#include <memory.h>
#include "Invoice.h"
Invoice* newInvoice(int id, double toPay, int maxCapacity){
    Invoice* invoice1 = malloc(sizeof(Invoice));
    invoice1->id = id;
    invoice1->toPay=toPay;
    invoice1->invoiceLineArray=malloc(sizeof(InvoiceLine)*maxCapacity);
    invoice1->currentInvoiceLine=0;
    return invoice1;
}

void addInvoiceLine(Invoice* invoice,InvoiceLine* invoiceLine){
    invoice->invoiceLineArray[invoice->currentInvoiceLine]=newInvoiceLine(invoiceLine->quantity,invoiceLine->article);
    invoice->currentInvoiceLine++;
}

void freeInvoice(Invoice* invoice1){
    for(int i=0;i<invoice1->currentInvoiceLine;i++){
        freeInvoiceLine(invoice1->invoiceLineArray[i]);
    }
    free(invoice1->invoiceLineArray);
    free(invoice1);
}