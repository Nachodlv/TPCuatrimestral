//
// Created by Ignacio on 10/5/2017.
//

#ifndef TPCUATRIMESTRAL_INVOICELINE_H
#define TPCUATRIMESTRAL_INVOICELINE_H
typedef struct invoiceLine InvoiceLine;
struct invoiceLine{
    char* id;
    char* article;
    int quantity;
};
InvoiceLine* newInvoiceLine(char* id, char* article);
void freeInvoiceLine(InvoiceLine* invoiceLine1);


#endif //TPCUATRIMESTRAL_INVOICELINE_H
