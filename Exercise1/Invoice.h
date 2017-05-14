//
// Created by Ignacio on 10/5/2017.
//

#ifndef TPCUATRIMESTRAL_INVOICE_H
#define TPCUATRIMESTRAL_INVOICE_H
typedef struct invoice Invoice;
struct invoice{
    int id;
    double toPay;
};

Invoice* newInvoice(int id, double toPay);
void freeInvoice(Invoice* invoice1);
#endif //TPCUATRIMESTRAL_INVOICE_H
