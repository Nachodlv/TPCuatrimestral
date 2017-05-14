//
// Created by Ignacio on 10/5/2017.
//

#ifndef TPCUATRIMESTRAL_INVOICE_H
#define TPCUATRIMESTRAL_INVOICE_H

#include "InvoiceLine.h"

typedef struct invoice Invoice;
struct invoice{
    int id;
    double toPay;
    InvoiceLine** invoiceLineArray;
    int* booleanArray;
    int maxCapacity;
    int currentInvoiceLine;
};

Invoice* newInvoice(int id, double toPay, int maxCapacity);
void freeInvoice(Invoice* invoice1);
void addInvoiceLine(Invoice* invoice,InvoiceLine* invoiceLine);
#endif //TPCUATRIMESTRAL_INVOICE_H
