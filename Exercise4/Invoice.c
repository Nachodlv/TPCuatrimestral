//
// Created by Oscar on 23/05/2017.
//

#include "Invoice.h"
#include <stdlib.h>
#include <memory.h>
Invoice* newInvoice(int invoiceNumber, int nitHotel, char* hotelName, char* clientName, int clientDni, double price){
    Invoice* invoice = malloc(sizeof(Invoice));
    invoice->invoiceNumber=invoiceNumber;
    invoice->nitHotel=nitHotel;
    invoice->hotelName=malloc(sizeof(char)*strlen(hotelName));
    invoice->clientName=malloc(sizeof(char)*strlen(clientName));
    invoice->clientDni=clientDni;
    invoice->price=price;
    strcpy(invoice->hotelName,hotelName);
    strcpy(invoice->clientName,clientName);
    return invoice;
}
void free(Invoice* invoice){
    free(invoice->hotelName);
    free(invoice->clientName);
    free(invoice);
}