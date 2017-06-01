//
// Created by Oscar on 23/05/2017.
//

#include "Invoice.h"
#include <stdlib.h>
#include <memory.h>
Invoice* newInvoiceExercise4(int invoiceNumber, int nitHotel, char* hotelName, char* clientName, int clientDni, double price){
    Invoice* invoice = malloc(sizeof(Invoice));
    invoice->invoiceNumber=invoiceNumber;
    invoice->nitHotel=nitHotel;
    invoice->hotelName=malloc(sizeof(char)*(strlen(hotelName)+1));
    invoice->clientName=malloc(sizeof(char)*(strlen(clientName)+1));
    invoice->clientDni=clientDni;
    invoice->price=price;
    strcpy(invoice->hotelName,hotelName);
    strcpy(invoice->clientName,clientName);
    return invoice;
}
void freeInvoiceExercise4(Invoice* invoice){
    free(invoice->hotelName);
    free(invoice->clientName);
    free(invoice);
}