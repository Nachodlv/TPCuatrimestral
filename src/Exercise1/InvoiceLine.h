//
// Created by Ignacio on 14/5/2017.
//

#ifndef TPCUATRIMESTRAL_INVOICELINE_H
#define TPCUATRIMESTRAL_INVOICELINE_H
typedef struct invoiceLine InvoiceLine;
struct invoiceLine{
    int quantity;
    char* article;
};
InvoiceLine* newInvoiceLine(int quantity, char* article);
void freeInvoiceLine(InvoiceLine* invoiceLine1);

#endif //TPCUATRIMESTRAL_INVOICELINE_H
