//
// Created by Oscar on 23/05/2017.
//

#ifndef TPCUATRIMESTRAL_INVOICE_H
#define TPCUATRIMESTRAL_INVOICE_H

typedef struct invoice Invoice;
struct invoice{
    int invoiceNumber;
    int nitHotel;
    char* hotelName;
    char* clientName;
    int clientDni;
    double price;
};
Invoice* newInvoiceExercise4(int invoiceNumber, int nitHotel, char* hotelName, char* clientName, int clientDni, double price);
void freeInvoiceExercise4(Invoice* invoice);
#endif //TPCUATRIMESTRAL_INVOICE_H
