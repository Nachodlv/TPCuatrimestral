//
// Created by Oscar on 23/05/2017.
//

#ifndef TPCUATRIMESTRAL_INVOICE_H
#define TPCUATRIMESTRAL_INVOICE_H

#include "Receptionist.h"
#include "Hotel.h"
#include "Client.h"
typedef struct invoice Invoice;
struct invoice{
    int invoiceNumber;
    int nitHotel;
    char* hotelName;
    char* clientName;
    int clientDni;
    double price;
};
Invoice* newInvoice(int invoiceNumber, int nitHotel, char* hotelName, char* clientName, int clientDni, double price);
void free(Invoice* invoice);
#endif //TPCUATRIMESTRAL_INVOICE_H
